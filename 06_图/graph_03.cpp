// - 实现图的深度优先搜索、广度优先搜索
#include <bits/stdc++.h>

using namespace std;
const int maxn=10;
int graph[maxn][maxn];
bool visited[maxn][maxn];
void dfs(int p){
    for(int i=0;i<maxn;i++){
        if(visited[p][i]==false and graph[p][i]!=-1){
            visited[p][i]=true;
            visited[i][p]=true;
            cout<<graph[p][i]<<" ";
            dfs(i);
        }
        
    }
}
void dfsTravel(){
    cout<<"DFS:";
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<maxn;i++){
        dfs(i);
    }
    cout<<endl;
}
void bfs(int p){
    queue<int> q;
    for(int i=0;i<maxn;i++){
        if(visited[p][i]==false and graph[p][i]!=-1){
            visited[p][i]=true;
            visited[i][p]=true;
            cout<<graph[p][i]<<" ";
            q.push(i);
        }
    }
    while(!q.empty()){
        bfs(q.front());
        q.pop();
    }
}
void bfsTravel(){
    cout<<"BFS:";
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<maxn;i++){
        bfs(i);
    }
    cout<<endl;
}
int main(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++)
            graph[i][j]=-1;
    }
    graph[0][1]=1;graph[0][2]=2;graph[0][3]=3;graph[1][2]=4;graph[2][3]=5;
    graph[1][0]=1;graph[2][0]=2;graph[3][0]=3;graph[2][1]=4;graph[3][2]=5;
    dfsTravel();
    bfsTravel();
    return 0;
}