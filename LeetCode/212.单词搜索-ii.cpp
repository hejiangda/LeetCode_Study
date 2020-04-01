/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution {
public:
    set<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string word:words) {
            trie.insert(word);
        }
        int m=board.size();
        int n=board[0].size();
        bool visited[m][n];
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
        visited[i][j]=false;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dfs(board,&visited[0][0],"",i,j,trie);
            }
        }
        vector<string> ret;
        for(auto& x:res)
            ret.push_back(x);
        return ret;
    }
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
    void dfs(vector<vector<char>>& board,bool* visited,string str,int x,int y,Trie &trie) {
        if(x<0||x>=board.size() ||y<0||y>=board[0].size())return;
        int n=board[0].size();
        if(visited[x*n+y])return;
        str+=board[x][y];
        if(!trie.startsWith(str))return;
        if(trie.search(str)) {
            res.insert(str);
        }
        visited[x*n+y]=true;
        dfs(board,visited,str,x-1,y,trie);
        dfs(board,visited,str,x+1,y,trie);
        dfs(board,visited,str,x,y-1,trie);
        dfs(board,visited,str,x,y+1,trie);
        visited[x*n+y]=false;
    }

};
// @lc code=end

