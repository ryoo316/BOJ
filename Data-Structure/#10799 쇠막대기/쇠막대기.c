#include<stdio.h>
char stack[100001] = {};
int top = 0;
void push(char n){
  stack[++top] = n;
}
void pop(){
  stack[--top] = 0;
}
int main(){
  char a[100001] = {};
  scanf("%s",a);

  int sum = 0;
  
  for(int i=0;a[i] != '\0';i++){
    if(a[i] == '(')
      push(a[i]);
    else{
      pop();
      if(a[i-1] == '('){
        sum += top;
      }
      else{
        sum++;
      }
    }
  }
  printf("%d",sum);
}