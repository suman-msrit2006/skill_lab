#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<string> top5; // store top 5 frequent words
};

class Autocomplete {
private:
    TrieNode* root;
    unordered_map<string, int> freq;

    void updateTop5(TrieNode* node, const string& word) {
        if (find(node->top5.begin(), node->top5.end(), word) == node->top5.end())
            node->top5.push_back(word);

        sort(node->top5.begin(), node->top5.end(),
             [&](string &a, string &b) {
                 return freq[a] > freq[b];
             });

        if (node->top5.size() > 5)
            node->top5.pop_back();
    }

public:
    Autocomplete() { root = new TrieNode(); }

    void insert(string word) {
        freq[word]++;
        TrieNode* node = root;

        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            node = node->children[c];
            updateTop5(node, word);
        }
    }

    vector<string> search(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) return {};
            node = node->children[c];
        }
        return node->top5;  // O(1)
    }
};