#include<stdio.h>
int stack[100001] = {};
int n;
int top = -1;
void push(int v){
  stack[++top] = v;
}
int pop(){
  return stack[top--];
}
int main(){
  scanf("%d",&n);
  int a;
  int cur = 1;
  int flag = 1;
  int t = 0;
  char ans[1000000] = {};
  for(int i=1;i<=n;i++){
    scanf("%d",&a);
    while(cur <= a){
      push(cur);
      ans[++t] = '+';
      cur++;
    }
    if(stack[top] == a){
      pop();
      ans[++t] = '-';
    }
    else
      flag = 0;
  }
  if(flag){
    for(int i=1;ans[i] != '\0';i++){
      printf("%c\n",ans[i]);
    }
  }
  else
    printf("NO");
}