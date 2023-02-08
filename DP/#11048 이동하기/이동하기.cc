#include<iostream>
#include<algorithm>
#include<cstring>
#define Max 1001
using namespace std;
int dp[Max][Max] = {};
int Matrix[Max][Max] = {};
int h, w;
void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
    }
  }
}

int solve(){
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + Matrix[i][j];
    }
  }
  return dp[h][w];
}

int main(){
  input();
  cout << solve();
  return 0;
}