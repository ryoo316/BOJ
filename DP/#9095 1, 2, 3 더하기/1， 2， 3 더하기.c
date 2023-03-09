#include<stdio.h>//1 2 4 7
int f(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    if(n>3) return f(n-1) + f(n-2) + f(n-3);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("%d\n",f(n));
    }
}
