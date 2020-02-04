// - 实现一个 LRU 缓存淘汰算法

#include <bits/stdc++.h>

using namespace std;
// 链表版
class LRU{
public:
    bool find(int x){
        for(int c:data){
            if(c==x){
                data.remove(x);
                data.push_front(x);
            }
        }
        return false;
    }
    LRU& insert(int x){
        data.push_back(x);
        return *this;
    }
    LRU& print(){
        cout<<"LRU:";
        for(int x:data){
            cout<<x<<" ";
        }
        cout<<endl;
        return *this;
    }
    
private:
    list<int> data;
};


int main(){
    LRU lru;
    lru.insert(1).insert(2).insert(3).insert(4).insert(5).insert(6).insert(7);
    lru.print();
    lru.find(3);
    lru.find(6);
    lru.print();
    return 0;
}