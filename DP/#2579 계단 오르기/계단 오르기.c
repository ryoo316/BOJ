#include<stdio.h>

int score[301] = {};
int memo[301] = {};

int max(int x, int y){
  if(x>y) return x;
  else return y;
}
int stair(int n){
  if(memo[n]) return memo[n];
  if(n==0) return 0;
  if(n==1) return memo[1] = score[1];
  else if(n==2) return memo[2] = score[1] + score[2];
  else{
    return memo[n] = max(stair(n-2), stair(n-3) + score[n-1]) + score[n];  
  }
}
int main(){
  int n;
  
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&score[i]);
  }
  printf("%d",stair(n));
}