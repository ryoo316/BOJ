#include<stdio.h>
#include<string.h>
int front = 0;
int rear = 0;
int size = 0;
int deque[10001] = {};

int empty(){
  if(front == rear)
    return 1;
  else 
    return 0;
}
void push_back(int v){
  deque[rear++] = v;
  size++;
}
void push_front(int v){
  for(int i=rear;i>=0;i--){
    deque[i+1] = deque[i];
  }
  rear++;
  deque[front] = v;
  size++;
}
int pop_back(){
  if(empty()){
    printf("-1\n");
    return 0;
  }
  else{
    printf("%d\n",deque[rear-1]);
    deque[rear-1] = 0;
    rear--;
    size--;
  }
  return 0;
}

int pop_front(){
  if(empty()){
    printf("-1\n");
    return 0;
  }
  else{
    printf("%d\n",deque[front]);
    deque[front] = 0;
    for(int i=front+1;i<rear;i++){
      deque[i-1] = deque[i];
    }
    rear--;
    size--;
  }
  return 0;
}
void f(){
  if(size== 0)
    printf("-1\n");
  else
    printf("%d\n",deque[front]);
}

void back(){
  if(size == 0) 
    printf("-1\n");
  else 
    printf("%d\n",deque[rear-1]);
}
int main()
{
  int n;
  scanf("%d",&n);
  getchar();
  for(int t=0;t<n;t++){
    char command[10] = {};
    scanf("%s",command);
    if(strcmp("push_back", command) == 0){
      int n;
      scanf("%d", &n);
      getchar();
      push_back(n);
    }
    if(strcmp("push_front", command) == 0){
      int n;
      scanf("%d", &n);
      getchar();
      push_front(n);
    }
    else if(strcmp("pop_front", command) == 0){
      pop_front();
    }
    else if(strcmp("pop_back", command) == 0){
      pop_back();
    }
    else if(strcmp("front", command) == 0){
      f();
    }
    else if(strcmp("size", command) == 0){
      printf("%d\n",size);
    }
    else if(strcmp("empty", command) == 0){
      printf("%d\n",empty());
    }
    else if(strcmp("back", command) == 0){
      back();
    }
  }
}