#include<iostream>
#define Max 1001
using namespace std;
int dp[1001];

int n;
int main(){
  cin >> n;
  dp[1] = 0;
  dp[2] = 1;
  for(int i=3;i<=n;i++){
    dp[i] = dp[i-2];
  }
  if(dp[n])
    cout << "SK";
  else
    cout << "CY";
}