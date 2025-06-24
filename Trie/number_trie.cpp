//max xor of 2 elements in an array

#include<bits/stdc++.h>
using namespace std;

class Trie
{
public : 
    struct Node
    {
        Node *left,*right;
        Node(){
            left=NULL;
            right=NULL;
        }
    };

    Node * root;

    Trie()
    {
        root=new Node();
    }

    void insert(int num)
    {
        Node * temp=root;

        for(int i=31;i>=0;i--)
        {
            if((num>>i) & 1 ){
                if(temp->right==NULL)temp->right=new Node();
                temp=temp->right;
            }else{
                if(temp->left==NULL)temp->left=new Node();
                temp=temp->left;
            }
        }

    }

    int maxxor(int num)
    {
        Node * temp=root;

        int ans=0;

        for(int i=31;i>=0;i--)
        {
            if(((num>>i)&1)){
                if(temp->left!=NULL){
                    ans+=(1<<i);
                    temp=temp->left;
                }else temp=temp->right;
            }else{
                if(temp->right!=NULL){
                    ans+=(1<<i);
                    temp=temp->right;
                }else temp=temp->left;
            }
            
        }
        return ans;
    }

};




int main()
{
    int n;cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    Trie t;
    for(auto x : nums)t.insert(x);

    int ans=0;
    for(auto x : nums)ans=max(ans,t.maxxor(x));

    cout << ans << "\n"; 
}