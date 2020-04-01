/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    struct T{
        bool isWorld=false;
        T* data[26]{nullptr};
    }tree;

    /** Inserts a word into the trie. */
    void insert(string word) {
        T* p=&tree;
        for(auto& x:word) {
            if(p->data[x-'a']==nullptr) {
                p->data[x-'a']=new T;
            }
            p=p->data[x-'a'];
        }
        p->isWorld=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        T* p=&tree;
        for(auto& x:word) {
            if(p->data[x-'a']==nullptr)return false;
            p=p->data[x-'a'];
        }
        if(p->isWorld)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        T* p=&tree;
        for(auto& x:prefix) {
            if(p->data[x-'a']==nullptr)return false;
            p=p->data[x-'a'];
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
// @lc code=end

