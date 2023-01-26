#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int main(){
  stack<char> stk;
  stack<char> arrow;
  char str[100001] = {};
  cin.getline(str, 100001, '\n');
  int len = strlen(str);
  str[len] = ' ';
  for(int i=0;i<=len;i++){
    if(str[i] == '<'){
      arrow.push('<');
      cout << "<";
    }
    else if(str[i] == '>'){
      arrow.pop();
      cout << ">";
    }
    else if(str[i] != ' '){//공백이 아니면
      if(!arrow.empty() && arrow.top() == '<')
        cout << str[i];
      else if(str[i+1] == '<'){
        stk.push(str[i]);
        while(!stk.empty()){
          cout << stk.top();
          stk.pop();
        }
      }
      else
        stk.push(str[i]);
    }
    else if(str[i] == ' '){
      if(!arrow.empty() && arrow.top() == '>')
        cout << str[i];
      else{
        while(!stk.empty()){
          cout << stk.top();
          stk.pop();
        }
        if(i != len)
          cout << " ";
      }
    }
  }
  return 0;
}