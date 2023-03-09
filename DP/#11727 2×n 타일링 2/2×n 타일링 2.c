#include<stdio.h>
#define d 10007
int memo[10001];
int dp(int n)
{
    if(memo[n]) return memo[n];
    if(n==1) return 1;
    if(n==2) return 3;
    if(n>2) return memo[n] = (dp(n-1)%d+2*dp(n-2)%d)%d;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",dp(n)%d);
}

