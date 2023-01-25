#include<stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  for(int k=0;k<t;k++){
    char str[51] = {};
    int top = -1, flag = 0;
    scanf("%s",str);
    for(int i=0;str[i] != '\0';i++){
      if(str[i] == '(') 
        top++;
      else if(str[i] == ')'){
        if(top == -1){
          flag = 1;
        }
        top--;
      }
    }
    if(flag){
      printf("NO\n");
    }
    else{
      if(top == -1) printf("YES\n");
      else printf("NO\n");
    }
  }
}