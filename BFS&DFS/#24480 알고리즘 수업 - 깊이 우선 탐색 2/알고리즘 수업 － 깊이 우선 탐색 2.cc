#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX_VALUE 100001
using namespace std;

int n, m, start, cnt = 1;

int visited[MAX_VALUE] = {};
int ans[MAX_VALUE] = {};

vector<int> adj[MAX_VALUE];
void dfs(int now)
{
  visited[now] = 1;
  
  ans[now] = cnt++;
  
  for(int i=adj[now].size()-1;i>=0;i--){
    int y = adj[now][i];

    if(visited[y])continue;
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
  for(int i=1;i<=n;i++){
    sort(adj[i].begin(),adj[i].end());
  }
  dfs(start);
  for(int i=1;i<=n;i++){
    printf("%d\n",ans[i]);
  }
}