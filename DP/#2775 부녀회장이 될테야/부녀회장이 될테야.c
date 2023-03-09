#include<stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t>0){
    int n,k;
    int dp[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++){
      for(int j=1;j<=n;j++){
      dp[j] += dp[j-1];
      }
    }
    printf("%d\n",dp[n-1]);
    t--;
  }

}