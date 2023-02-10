#include<iostream>
#include<vector>
using namespace std;

int n, m;
int a, b;
int ans = 1000000;

int visited[101] = {};

vector<int> adj[101];

void DFS(int now, int cnt){
  visited[now] = 1;

  if(now == b)
    ans > cnt ? ans = cnt : ans = 1000000;
  
  for(int i=0;i<adj[now].size();i++){
    int next = adj[now][i];
    if(visited[next])continue;
    visited[next] = 1;
    DFS(next, cnt + 1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> a >> b;
  cin >> m;
  for(int i=0;i<m;i++){
    int s, e;
    cin >> s >> e;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  DFS(a, 0);
  if(ans == 1000000)
    cout << -1;
  else
    cout << ans;
  return 0;
}