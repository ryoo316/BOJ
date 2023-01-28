#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[100001];

int visited[100001] = {};
int ans[100001] = {};

void dfs(int start){
  visited[start] = 1;
  for(int i=0;i<adj[start].size();i++){
    int next = adj[start][i];
    if(visited[next])continue;
    ans[next] = start;
    dfs(next);
  }
}

int main(){
  int n;
  cin >> n;
  for(int i=1;i<n;i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  for(int i=2;i<=n;i++){
    cout << ans[i] << "\n";
  }
}