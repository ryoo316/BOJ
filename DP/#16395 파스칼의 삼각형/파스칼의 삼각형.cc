#include<stdio.h>
int memo[31][31] = {};
int dp(int n, int r)
{
  if(memo[n][r]) return memo[n][r];
  if(r == 1 || n == r) return 1;
  return memo[n][r] = dp(n-1,r) + dp(n-1,r-1);
}
int main()
{
  int n,r;
  scanf("%d%d",&n,&r);
  printf("%d",dp(n,r));
}