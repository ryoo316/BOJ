#include<iostream>
using namespace std;

int n;
int coin[3] = {2, 5};
int dp[100001] = {};

int main(){
  cin >> n;

  for(int i=1;i<=n;i++)
    dp[i] = 1000000;
  for(int i=0;i<2;i++){
    for(int j=coin[i];j<=n;j++){
      if(dp[j-coin[i]] < 0)
        break;
      else
        dp[j] = min(dp[j], dp[j-coin[i]] + 1);
    }
  }
  if(dp[n] == 1000000)
    cout << -1;
  else
    cout << dp[n];
  return 0;
}