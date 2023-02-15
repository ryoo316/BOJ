#include<stdio.h>
char stack[31] = {};
int top = -1;
void push(char n){
  stack[++top] = n;
}
void pop(){
  stack[top--] = 0;
}
int main(){
  char a[31] = {};
  scanf("%s",a);

  int ans = 0, cnt = 1;
  
  for(int i=0;a[i] != '\0';i++){
    if(a[i] == '('){
      push(a[i]);
      cnt *= 2;
    }
    else if(a[i] == '['){
      push(a[i]);
      cnt *= 3;
    }
    else if(a[i] == ')'){
      if(stack[top] == 0 || stack[top] != '('){
        ans = 0;
        break;
      }      
      if(a[i-1] == '('){
        ans += cnt;
        cnt /= 2;
        pop();
      }
      else{
        cnt /= 2;
        pop();
      }
    }
    else if(a[i] == ']'){
      if(stack[top] == 0 || stack[top] != '['){
        ans = 0;
        break;
      }
      if(a[i-1] == '['){
        ans += cnt;
        cnt /= 3;
        pop();
      }      
      else{
        cnt /= 3;
        pop();
      }
    }
  }
  if(stack[top] != 0) ans = 0;
  printf("%d",ans);
  return 0;
}