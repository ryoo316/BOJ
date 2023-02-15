#include<stdio.h>
#include<string.h>

int stack[100001] = {};

int top = -1;
void push(int v)
{
  stack[++top] = v;
}
void pop()
{
  stack[top] = 0;
  top--;
}
int main()
{
  int k,sum = 0;
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    int n;
    scanf("%d",&n);
    if(n != 0){
      push(n);
    }
    else pop();
  };
  for(int i=0;stack[i] != '\0';i++){
    sum += stack[i];
  }
  printf("%d",sum);
}