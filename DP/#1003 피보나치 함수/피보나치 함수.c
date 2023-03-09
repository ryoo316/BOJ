#include<stdio.h>
int dp[41] = {};
int main()
{
  dp[0] = 0;
  dp[1] = 1;
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    int n;
    scanf("%d",&n);
    for(int j=2;j<=n;j++){
      dp[j] = dp[j-1] + dp[j-2];
    }
    if(n==0) printf("1 0\n");
    else
    printf("%d %d\n",dp[n-1],dp[n]);
  }
}