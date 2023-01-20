#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define MAX_VALUE 100001
using namespace std;

int n, m, start;

int visited1[MAX_VALUE] = {};
int visited2[MAX_VALUE] = {};

vector<int> adj[MAX_VALUE];
queue<int> a;
void bfs(int now)
{
  visited1[now] = 1;
  
  a.push(now);
  
  while(!a.empty()){
    int cur = a.front();
    printf("%d ",cur);
    a.pop();
    
    for(int i=0;i<adj[cur].size();i++){
      int y = adj[cur][i];
      if(visited1[y])continue;
      visited1[y] = 1;
      a.push(y);
    }
  }
}
void dfs(int now)
{
  visited2[now] = 1;
  
  printf("%d ",now);

  for(int i=0;i<adj[now].size();i++){
    int y = adj[now][i];
    if(visited2[y])continue;
    dfs(y);
  }
}
int main()
{
  scanf("%d%d%d",&n,&m,&start);
  for (int i=0;i<m;i++){
    int a, b;
    scanf("%d%d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
  dfs(start);
  printf("\n");
  bfs(start);
}