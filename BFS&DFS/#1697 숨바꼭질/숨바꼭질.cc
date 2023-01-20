#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int visited[200001] = {};
int ans[200001] = {};
int n,k,t = 0;

int bfs(int n){
  queue<int> a;

  a.push(n);
  visited[n] = 1;
  while(!a.empty()){
    int now = a.front();
    a.pop();
    //동생 위치에 도착하면 답 출력후 반복문 빠져나가기
    if(now == k){
      printf("%d",ans[now]);
      break;
    }
    if(now>=0){
      if(visited[now + 1] == 0){
        a.push(now + 1);
        ans[now + 1] = ans[now] + 1;
        visited[now + 1] = 1;
      }
    }
    if(now>=0){
      if(visited[now - 1] == 0){
        a.push(now - 1);
        ans[now - 1] = ans[now] + 1;
        visited[now - 1] = 1;
      }
    }
    if(now * 2 >= 0 && now * 2 <= 100000){
      if(visited[now * 2] == 0){
        a.push(now * 2);
        ans[now * 2] = ans[now] + 1;
        visited[now * 2] = 1;
      }
    }
  }  
  return 0;
}
int main(){
  scanf("%d%d",&n,&k);
  if(n >= k){
    printf("%d",n-k);
    return 0;
  }
  bfs(n);
}