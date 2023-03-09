#include<stdio.h>
#define d 10007
int memo[1001] = {};
int f(int n){
    if(memo[n]) return memo[n];
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n>2) return memo[n] = f(n-1)%d + f(n-2)%d;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n)%d);
}
