// - 实现有向图、无向图、有权图、无权图的邻接矩阵和邻接表表示方法
// 有向图
#include <bits/stdc++.h>

using namespace std;
// 邻接矩阵
class UndirGraph{
public:
    UndirGraph(int sz){
        this->sz=sz;
        data.resize(sz);
        for(vector<int>& x:data){
            x.resize(sz);
            for(int& c:x){
                c=-1;
            }
        }
    }
    UndirGraph& set(int i,int j,int x){
        if(i<sz and j<sz and i!=j){
            data[i][j]=x;
        }
        return *this;
    }
    int get(int i,int j){
        if(i<sz and j<sz){
            return data[i][j];
        }
        return -1;
    }
    UndirGraph& print(){
        cout<<"Graph:"<<endl;
        for(vector<int> v:data){
            for(int x:v){
                cout<<x<<'\t';
            }
            cout<<endl;
        }
        return *this;
    }
private:
    int sz;
    vector<vector<int>> data;
};
// 邻接表
class UndirGraphList{
public:
    UndirGraphList(int sz){
        this->sz=sz;
        data.resize(sz);

    }
    UndirGraphList& set(int i,int j,int x){
        if(i<sz and j<sz and i!=j){
            bool flg=true;
            for(auto& c:data[i]){
                if(c.first==j){
                    c.second=x;
                    flg=false;
                }
            }
            if(flg)
                data[i].push_back(pair<int,int>(j,x));
        }
        return *this;
    }
    int get(int i,int j){
        if(i<sz and j<sz and i!=j){
            for(auto c:data[i]){
                if(c.first==j){
                    return c.second;
                }
            }
        }
        return -1;
    }
    UndirGraphList& print(){
        cout<<"Graph:"<<endl;
        int i=0;
        for(auto v:data){
            cout<<i++<<": { ";
            for(auto x:v){
                cout<<"[j: "<<x.first<<" val: "<<x.second<<"] ";
            }
            cout<<"}\n";
        }
        return *this;
    }
private:
    vector<list<pair<int,int>>> data;
    int sz;
};
int main(){
    UndirGraph g(5);
    g.set(0,1,1).set(0,2,2).set(0,3,3).set(1,2,4).set(2,3,5);
    g.print();   

    UndirGraphList gl(5);
    gl.set(0,1,1).set(0,2,2).set(0,3,3).set(1,2,4).set(2,3,5);
    gl.print();

    return 0;
}