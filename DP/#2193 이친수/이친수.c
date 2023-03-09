#include<stdio.h>
unsigned long long memo[91] = {};
unsigned long long f(unsigned long long n){
    if(memo[n]) return memo[n];
    if(n==1) return 1;
    else if(n==2) return 1;
    else if(n>2) return memo[n] = f(n-1) + f(n-2);
}
int main()
{
    unsigned long long n;
    scanf("%llu",&n);   
    printf("%llu",f(n));
}
