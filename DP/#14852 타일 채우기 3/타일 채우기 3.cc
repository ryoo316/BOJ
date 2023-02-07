#include<iostream>
#define MOD 1000000007
using namespace std;
long long dp[1000001][2] = {};
//(dp[n] = 2*dp[n-1] + 3*dp[n-2] + 2*(Sum(n-3))
int main(){
  dp[0][0] = 0;
  dp[1][0] = 2;
  dp[2][0] = 7;
  dp[2][1] = 1;
  //dp[n][0]은 dp값
  //dp[n][1]은 dp[n-3][0] 부터 dp[0][0]까지 합산된 값
  int n;
  cin >> n;
  for(int i=3;i<=n;i++){
    dp[i][1] = (dp[i-1][1] + dp[i-3][0])%MOD;//(i-4)까지의 합(sum(i-3))
    dp[i][0] = (2*dp[i-1][0] + 3*dp[i-2][0] + 2*dp[i][1])%MOD;
  }
  cout << dp[n][0];
}