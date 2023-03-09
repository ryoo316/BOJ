#include <stdio.h>
#define d 10007
int memo[1001][1001] = {};
int dp(int n, int r)
{
  if(memo[n][r]) return memo[n][r];
  if(r==0 || n==r)
    return 1;
  else
    return memo[n][r] = (dp(n-1, r-1)%d+dp(n-1, r)%d)%d;
}
 
int main()
{
  int n, r;
  scanf("%d %d", &n, &r);
  printf("%d\n", dp(n, r));
  return 0;
}