#include <bits/stdc++.h>
using namespace std;

class Trie {
public :
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    void deleteNode(TrieNode* node, std::string key, int depth) {
        if (node == nullptr) {
            return;
        }

        if (depth == key.length()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
            }
            // Check if node can be deleted
            bool isEmpty = true;
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty) {
                delete node;
                node = nullptr;
            }
            return;
        }

        int index = key[depth] - 'a';
        deleteNode(node->children[index], key, depth + 1);

        // After deletion of child node, check if current node can be deleted
        if (!node->isEndOfWord) {
            bool isEmpty = true;
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty) {
                delete node;
                node = nullptr;
            }
        }
    }

    Trie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(std::string key) {
        TrieNode* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return (current != nullptr && current->isEndOfWord);
    }

    void deleteString(std::string key) {
        deleteNode(root, key, 0);
    }
};