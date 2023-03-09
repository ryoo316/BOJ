#include<stdio.h>
#define d 9901
int memo[100001] = {};

int f(int n){
  if(memo[n]) return memo[n];
  if(n==1) return memo[1] = 3;
  else if(n==2) return memo[2] = 7;
  else{
    return memo[n] = (f(n-1)*2%d + f(n-2)%d)%d;
  }
}
int main(){
  int n;
  scanf("%d",&n);
  printf("%d",f(n));
  return 0;
}