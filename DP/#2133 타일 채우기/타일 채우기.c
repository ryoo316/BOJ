#include<stdio.h>
int memo[31] = {};
int dp(int n){
  if(memo[n]) return memo[n];
  if(n == 0)
    return 1;
  else if(n == 2)
    return 3;
  else
    return memo[n] = dp(n-2)*4 - dp(n-4);
}
int main(){
  int n;
  scanf("%d",&n);
  if(n%2==1){
    printf("%d",0);
    return 0;
  }
  printf("%d",dp(n));
  return 0;
}