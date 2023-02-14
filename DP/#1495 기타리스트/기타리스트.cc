#include<iostream>
using namespace std;

int V[51] = {};
bool dp[51][1001] = {};//dp[i][j] = i번째일때 j번째 볼륨 가능여부판단

int n, s, m, ans;

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s >> m;
  for(int i=1;i<=n;i++)
    cin >> V[i];
}

void solve(){
  dp[0][s] = true;//시작볼륨
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(!dp[i-1][j])continue;
      if(j + V[i] <= m)
        dp[i][j + V[i]] = true;
      if(j - V[i] >= 0)
        dp[i][j - V[i]] = true;
    }
  }
}

int main(){
  input();

  solve();

  int flag = 1;
  for(int i=0;i<=m;i++){
    if(dp[n][i]){
      ans = i;
      flag = 0;
    }
  }
  if(!flag)
    cout << ans;
  else
    cout << -1;
  return 0;
}