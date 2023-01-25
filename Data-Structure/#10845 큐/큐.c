#include<stdio.h>
#include<string.h>
int front = -1;
int rear = -1;
int cnt = 0;
int queue[10001] = {};
void push(int v)
{
  rear++;
  cnt++;
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
  if(empty() == 1){
    printf("-1\n");
  }
  else{
    front++;
    cnt--;
    printf("%d\n",queue[front]);
    return queue[front];
  }
}
void f()
{
  if(cnt == 0) printf("-1\n");
  else printf("%d\n",queue[front+1]);
}
void back()
{
  if(cnt == 0) printf("-1\n");
  else printf("%d\n",queue[rear]);
}
void size(){
  printf("%d\n",cnt);
}
int main()
{
  int n;
  scanf("%d",&n);
  getchar();
  for(int t=0;t<n;t++){
    char command[10] = {};
    scanf("%s",command);
    
    if(strcmp("push", command) == 0){
      int n;
      scanf("%d", &n);
      getchar();
      push(n);
    }
    else if(command[0] == 'p'){
      pop();
    }
    else if(command[0] == 'f'){
      f();
    }
    else if(command[0] == 's'){
      size();
    }
    else if(command[0] == 'e'){
      printf("%d\n",empty());
    }
    else if(command[0] == 'b'){
      back();
    }
  }
}