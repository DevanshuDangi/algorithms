from google.colab import drive
drive.mount('/content/drive')

import os
os.chdir('/content/drive/MyDrive/ml-100k')

%matplotlib inline

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import random
from tqdm import tqdm_notebook
from copy import deepcopy

import os
from google.colab import drive
drive.mount('/content/drive')

# os.chdir('/content/drive/My Drive/recommendation system')


%matplotlib inline

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import random
from tqdm import tqdm_notebook
from copy import deepcopy

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader, Dataset
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

data_path = '/content/drive/MyDrive/ml-100k//'



id_val = 1
num_users = 943
num_items = 1682
train_dataframe = pd.read_csv(f'{data_path}u{id_val}.base',sep='\t',header=None)
train_dataframe.columns = ['user_id','item_id','rating','ts']
train_dataframe['user_id'] = train_dataframe['user_id'] -1
train_dataframe['item_id'] = train_dataframe['item_id'] -1
valid_df = pd.read_csv(f'{data_path}u{id_val}.test',sep='\t',header=None)
valid_df.columns = ['user_id','item_id','rating','ts']
valid_df['user_id'] = valid_df['user_id'] -1
valid_df['item_id'] = valid_df['item_id'] -1
train_dataframe.shape, valid_df.shape



train_usrs = train_dataframe.user_id.unique()
vald_usrs = valid_df.user_id.unique()
len(train_usrs),len(vald_usrs)
train_itms = train_dataframe.item_id.unique()
vald_itms = valid_df.item_id.unique()
len(train_itms),len(vald_itms)

train_usrs = train_dataframe.user_id.unique()
vald_usrs = valid_df.user_id.unique()
len(train_usrs),len(vald_usrs)
train_itms = train_dataframe.item_id.unique()
vald_itms = valid_df.item_id.unique()
len(train_itms),len(vald_itms)

class CollabDataset(Dataset):
    def __init__(self, df, user_col=0, item_col=1, rating_col=2):
        self.df = df
        self.user_tensor = torch.tensor(self.df.iloc[:,user_col], dtype=torch.long, device = device)
        self.item_tensor = torch.tensor(self.df.iloc[:,item_col], dtype=torch.long, device = device)
        self.target_tensor = torch.tensor(self.df.iloc[:,rating_col], dtype=torch.float32, device = device)

    def __getitem__(self, index):
        return(self.user_tensor[index], self.item_tensor[index], self.target_tensor[index])

    def __len__(self):
        return(self.user_tensor.shape[0])
batch_size = 2000
train_dataset = CollabDataset(train_dataframe)
train_dataloader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=4)
valid_dataset = CollabDataset(valid_df)
valid_dataloader = DataLoader(valid_dataset, batch_size=batch_size, shuffle=True, num_workers=4)


class ConcatNet(nn.Module):
    def __init__(self, config):
        super(ConcatNet, self).__init__()
        #hyperparameters
        self.config = config
        self.num_users = config['num_users']
        self.num_items = config['num_items']
        self.emb_size = config['emb_size']
        self.emb_droupout = config['emb_droupout']
        self.fc_layer_sizes = config['fc_layer_sizes']
        self.dropout = config['dropout']
        self.out_range = config['out_range']

        #embeddings
        self.emb_user = nn.Sequential(
            nn.Embedding(num_embeddings=self.num_users, embedding_dim=self.emb_size),
            nn.Dropout(p=self.emb_droupout))
        self.emb_item = nn.Sequential(
            nn.Embedding(num_embeddings=self.num_items, embedding_dim=self.emb_size),
            nn.Dropout(p=self.emb_droupout))

        #fully-connected layers
        fc_layers_list = []
        for ni,nf,p in zip(self.fc_layer_sizes[:-1], self.fc_layer_sizes[1:], self.dropout):
            fc_layers_list.append(nn.Linear(ni, nf))
            fc_layers_list.append(nn.ReLU(inplace=True))
            fc_layers_list.append(nn.BatchNorm1d(nf))
            fc_layers_list.append(nn.Dropout(p=p))
        self.fc_layers = nn.Sequential(*fc_layers_list)

        #output head
        self.head = torch.nn.Linear(in_features=self.fc_layer_sizes[-1], out_features=1)

    def forward(self, user_idx, item_idx):
        user_emb = self.emb_user(user_idx)
        item_emb = self.emb_item(item_idx)
        x = torch.cat([user_emb, item_emb], dim=1)
        x = self.fc_layers(x)
        x = torch.sigmoid(self.head(x))
        x = x * (self.out_range[1] - self.out_range[0]) + self.out_range[0]
        return(x)


config = {
    'num_users':943,
    'num_items':1682,
    'emb_size':50,
    'emb_droupout': 0.05,
    'fc_layer_sizes': [100, 512, 256],
    'dropout': [0.7,0.35],
    'out_range': [0.8,5.2]}
model = ConcatNet(config)
model



batch_size = 2000
learning_rate = 1e-2
weight_decay = 5e-1
num_epoch = 100
reduce_learning_rate = 1
early_stoping = 5

learning_rates = []
train_losses = []
valid_losses = []
best_loss = np.inf
best_weights = None

train_dataset = CollabDataset(train_dataframe)
train_dataloader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True, num_workers=4)
valid_dataset = CollabDataset(valid_df)
valid_dataloader = DataLoader(valid_dataset, batch_size=batch_size, shuffle=True, num_workers=4)

model = ConcatNet(config)
criterion = nn.MSELoss(reduction='sum')
optim = torch.optim.Adam(model.parameters(), lr=learning_rate, betas=(0.9, 0.999), weight_decay=weight_decay)
scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(optim, mode='min', factor=0.5, threshold=1e-3, patience=reduce_learning_rate, min_lr=learning_rate/10)


for e in tqdm_notebook(range(num_epoch)):
    model.train()
    train_loss = 0
    for u,i,r in train_dataloader:
        r_pred = model(u,i)
        r = r[:,None]

        loss = criterion(r_pred,r)

        optim.zero_grad()
        loss.backward()
        optim.step()
        train_loss += loss.detach().item()

    # Correct way to get the current learning rate
    current_learning_rate = optim.param_groups[0]['lr']
    learning_rates.append(current_learning_rate)
    train_loss /= len(train_dataset)
    train_losses.append(train_loss)

    model.eval()
    valid_loss = 0
    with torch.no_grad():
        for u,i,r in valid_dataloader:
            r_pred = model(u,i)
            r = r[:,None]
            loss = criterion(r_pred,r)
            valid_loss += loss.item()
    valid_loss /= len(valid_dataset)
    valid_losses.append(valid_loss)
    print(f'Epoch {e} Train loss: {train_loss:.4f}; Valid loss: {valid_loss:.4f}; Learning rate: {current_learning_rate:.6f}')

    if valid_loss < best_loss:
        best_loss = valid_loss
        best_weights = deepcopy(model.state_dict())
        no_improvements = 0
    else:
        no_improvements += 1

    if no_improvements >= early_stoping:
        print(f'Early stopping after epoch {e}')
        break

    scheduler.step(valid_loss)


