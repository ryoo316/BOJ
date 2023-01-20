#include<stdio.h>
#include<queue>
using namespace std;

typedef struct COORD{
  int x;
  int dist;
}coord;

int n, m;
int snake_ladder[101][2] = {};
int visited[101] = {};

int dx[6] = {1, 2, 3, 4, 5, 6};

int main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){//사다리
    int a, b;
    scanf("%d%d",&a,&b);
    snake_ladder[a][0] = b;//12 35
  }
  for(int i=0;i<m;i++){//뱀
    int a, b;
    scanf("%d%d",&a,&b);
    snake_ladder[a][1] = b;//35 12
  }
  queue<coord> a;
  a.push({1,0});
  visited[1] = 1;
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int dist = now.dist;
    a.pop();
    for(int i=0;i<6;i++){
      int nx = x + dx[i];
      if(nx > 100)continue;
      if(visited[nx])continue;
      if(nx == 100){//도착했다면
        printf("%d",dist+1);
        return 0;
      }
      int flag = 1;
      for(int i=1;i<=100;i++){
        if(snake_ladder[i][0] != 0 && nx == i){//사다리
          a.push({snake_ladder[i][0], dist + 1});
          flag = 0;
          }
        else if(snake_ladder[i][1] != 0 && nx == i){//뱀
          a.push({snake_ladder[i][1], dist + 1});
          flag = 0;
        }
      }
      if(flag){
        a.push({nx, dist + 1});
        visited[nx] = 1;
      }
    }
  }
}