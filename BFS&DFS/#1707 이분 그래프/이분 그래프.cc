#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;

int visited[20001];
vector<int> adj[20001];

void bfs(int s){
  queue<int> q;
  visited[s] = 1;
  q.push(s);
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i=0;i<adj[cur].size();i++){
      int next = adj[cur][i];
      if(!visited[next]){
        q.push(next);
        if(visited[cur] == 1)
          visited[next] = 2;
        else if(visited[cur] == 2)
          visited[next] = 1;
      }
    }
  }
}

int main(){
  int k;
  scanf("%d",&k);
  while(k>0){
    int v,e;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
      int a, b;
      scanf("%d%d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int flag = 0;
    for(int i=1;i<=v;i++){
      if(!visited[i])
        bfs(i);
    }
    for(int cur = 1; cur <= v; cur++){
      for(int i=0;i<adj[cur].size();i++){
        int next = adj[cur][i];
        if(visited[cur] == visited[next])
          flag = 1;
      }
    }
    if(flag)
      printf("NO\n");
    else
      printf("YES\n");
    
    memset(visited, 0, sizeof(visited));
    for(int i=1;i<=v;i++){
      adj[i].clear();
    }
    k--;
  }
}