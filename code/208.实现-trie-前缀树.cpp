/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
class Node {
public:
    Node* next[26];
    bool isEndOfNode;
    Node() : isEndOfNode(false) {
        for(int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }
};

class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
            {
                p->next[index] = new Node();
            }
            p = p->next[index];
        }
        p->isEndOfNode = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return p->isEndOfNode ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            int index = prefix[i] - 'a';
            if(p->next[index] == nullptr)
                return false;
            p = p->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

