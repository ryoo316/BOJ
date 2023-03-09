#include<stdio.h>
int c1=1,c2=0;
int fib(int n) {
    
    if (n == 1 || n == 2)
      return 1;
    else return fib(n - 1) + fib(n - 2);
}
int main()
{
  int n;
  scanf("%d",&n);

  printf("%d %d",fib(n),n-2);
}