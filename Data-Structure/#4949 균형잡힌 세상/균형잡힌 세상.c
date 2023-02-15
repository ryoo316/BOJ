#include<stdio.h>
int top1 = -1, top2 = -1;
int stack1[101] = {};
int stack2[101] = {};
void push1(int v){
  stack1[++top1] = v;
}
void push2(int v){
  stack2[++top2] = v;
}
int pop1(){
  if(top1 == -1) return top1;
  return stack1[top1--];
}
int pop2(){
  if(top2 == -1) return top2;
  return stack2[top2--];
}
int main()
{
  while(1){
    char str[101] = {};
    top1 = -1;
    top2 = -1;
    int flag = 1;
    scanf("%[^\n]s",str);
    getchar();
    
    if(str[0] == '.' && str[1] == '\0')
      return 0;
    
    for(int i=0;str[i] != '\0';i++){
      if(str[i] == '('){
        push1(top2);
      }
      else if(str[i] == ')'){
        int cur = top1;
        int pop = pop1();
        if(cur == -1 || pop < top2){
          flag = 0;
          break;
        }
      }
      if(str[i] == '['){
        push2(top1);
      }
      else if(str[i] == ']'){
        int cur = top2;
        int pop = pop2();
        if(cur == -1 || pop < top1){
          flag = 0;
          break;
        }
      }
    }
    if(top1 != -1 || top2 != -1) flag = 0;

    if(flag){
      printf("yes\n");
      continue;
    }
    else{
      printf("no\n");
      continue;
    }
  }
}