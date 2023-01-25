#include<iostream>
#include<cstring>
using namespace std;

typedef struct STACK_{
  int top;
  char stk[1001];
}STACK;

void push(STACK* s, char value){
  s->top +=1 ;
  s->stk[s->top] = value;
}
int isempty(STACK* s){
  if(s->top == -1)
    return 1;
  else
    return 0;
}
void pop(STACK* s){
  cout << s->stk[s->top];
  s->top--;
}
int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    STACK stack;
    stack.top = -1;
    char str[1001] = {};
    cin.getline(str, 1001, '\n');
    int len = strlen(str);
    str[len] = ' ';
    for(int i=0;i<=len;i++){
      if(str[i] != ' '){
        push(&stack, str[i]);
      }
      else if(str[i] == ' '){
        while(!isempty(&stack)){
          pop(&stack);
        }
        if(i != len)
          cout << " ";
      }
    }
    cout << "\n";
  }
}