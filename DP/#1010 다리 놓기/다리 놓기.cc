#include <stdio.h>
int memo[31][31] = {};
int dp(int n, int r)
{
  if(memo[n][r]) return memo[n][r];
  if(r==0 || n==r)
    return 1;
  else
    return memo[n][r] = dp(n-1, r-1)+dp(n-1, r);
}
 
int main()
{
  int t;
  scanf("%d",&t);
  while(t != 0){
    int n, r;
    scanf("%d %d", &r, &n);
    printf("%d\n", dp(n, r));
    t--;
  }
    return 0;
}