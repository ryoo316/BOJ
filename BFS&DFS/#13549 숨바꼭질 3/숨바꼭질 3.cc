#include<stdio.h>
#include<deque>
#include<algorithm>
using namespace std;

int ans[100001] = {0,};
int n,k;
deque<int> a;

int bfs(int n){
  
  a.push_back(n);
  ans[n] = 1;
  while(!a.empty()){
    int now = a.front();
    a.pop_front();
    if(now == k){
      return ans[k] - 1;
    }
    if(now * 2 < 100001 && !ans[now * 2]){//순간이동은 앞에다 넣는다
      a.push_front(now * 2);
      ans[now * 2] = ans[now];//0초후 순간이동
    }
    if(now + 1 < 100001 && !ans[now + 1]){
      a.push_back(now + 1);
      ans[now + 1] = ans[now] + 1;
    }
    if(now - 1 > -1 && !ans[now - 1]){
      a.push_back(now - 1);
      ans[now - 1] = ans[now] + 1;
    }
  }
  return -1;
}
int main(){
  scanf("%d%d",&n,&k);
  if(n >= k){
    printf("%d",n-k);
    return 0;
  }
  printf("%d",bfs(n));
}