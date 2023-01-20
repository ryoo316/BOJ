#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_VALUE 100001
using namespace std;

int n, m, start, cnt = 1;

int visited[MAX_VALUE] = {};
int ans[MAX_VALUE] = {};

vector<int> adj[MAX_VALUE];
queue<int> a;
void bfs(int now)
{
  visited[now] = 1;
  
  a.push(now);

  while(!a.empty()){
    int cur = a.front();
    ans[cur] = cnt++;
    a.pop();
    for(int i=adj[cur].size()-1;i>=0;i--){
      int y = adj[cur][i];
      if(visited[y] == 1)continue;
      visited[y] = 1;
      a.push(y);
    }
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
  bfs(start);
  for(int i=1;i<=n;i++){
    printf("%d\n",ans[i]);
  }
}