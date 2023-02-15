#include<stdio.h>
#include<string.h>
int front = -1;
int rear = -1;
int queue[1000001] = {};
void push(int v)
{
  rear++;
  queue[rear] = v;
}
int empty()
{
  if(front == rear)
    return 1;
  else 
    return 0;
}
int pop()
{
  front++;
  return queue[front];
}
int main()
{
  int n;
  scanf("%d",&n);
  if(n == 1){
    printf("1");
    return 0;
  }
  for(int i=1;i<=n;i++){
    push(i);
  }
  while(1){
    front++;
    if((front + 1) == rear){
      printf("%d",queue[rear]);
      return 0;
    }
    push(pop());
  }
}