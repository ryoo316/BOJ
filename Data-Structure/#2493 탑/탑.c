#include<stdio.h>
int memo[500001] = {};
int stack[500001] = {};
int ans[500001] = {};
int top = 0;
void pop(){
  stack[--top] = 0;
}
void push(int n, int i){
  if(i == 0){
    ans[i] = 0;
    stack[top++] = n;
  }
  else{
    /*stack[top-1] 부터 stack[0]까지 탐색*/
    for(int k=top-1;k>=0;k--){
      if(stack[k] < n){
        pop();
      }
      else{
        memo[k+1] = i;//위치 저장
        stack[k+1] = n;//스택에 값 push
        ans[i] = memo[k] + 1;//답 배열에 위치 넣기
        top = k + 2;
        break;
      }
    }
    if(stack[top] == 0 && top == 0){
      memo[top] = i;
      stack[top++] = n;
      ans[i] = 0;
    }
  }
}

int main(){
  int n;
  int a[500001] = {};
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    push(a[i], i);
  }
  for(int i=0;i<n;i++){
    printf("%d ",ans[i]);
  }
  return 0;
}