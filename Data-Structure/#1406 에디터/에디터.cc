#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stack>
using namespace std;

int main(){
  //왼쪽 오른쪽 스택 나누기
  stack<char> left;
  stack<char> right;
  char str[100001] = {};
  char st[600001] = {};
  cin >> str;
  //왼쪽 스택에 초기 문자열 넣어주기
  for(int i=0;str[i] != '\0';i++){
    left.push(str[i]);
  }
  int n;
  cin >> n;
  cin.ignore();
  for(int i=0;i<n;i++){
    char a[4] = {};
    cin.getline(a, 4, '\n');
    //왼쪽으로 옮기기
    if(a[0] == 'L' && !left.empty()){
      right.push(left.top());
      left.pop();
    }
    //오른쪽으로 옮기기
    if(a[0] == 'D' && !right.empty()){
      left.push(right.top());
      right.pop();
    }
    //지우기
    if(a[0] == 'B' && !left.empty()){
      left.pop();
    }
    //문자 추가하기
    if(a[0] == 'P'){
      left.push(a[2]);
    }
  }
  //오른쪽 스택이 남아있다면
  while(!right.empty()){
    left.push(right.top());//왼쪽 스택으로 다 옮겨주기
    right.pop();
  }
  int i = 0;
  //왼쪽 스택을 답 배열로 옮기기
  while(!left.empty()){
    st[i++] = left.top();
    left.pop();
  }
  int len = strlen(st);
  //답 출력
  for(int i=len-1;i>=0;i--)
    cout << st[i];
}