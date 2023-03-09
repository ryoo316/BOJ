#include<stdio.h>
int min(int a, int b){
  if(a>b) return b;
  else return a;
}
int main()
{
  int n;
  int dp[1000001] = {};
  scanf("%d",&n);
  dp[1] = 0;
  dp[2] = 1;
  for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + 1;
    if(i%3==0){
      dp[i] = min(dp[i/3] + 1,dp[i]);
    }
    if(i%2==0){
      dp[i] = min(dp[i/2] + 1,dp[i]);
    }
  }
  printf("%d",dp[n]);
}