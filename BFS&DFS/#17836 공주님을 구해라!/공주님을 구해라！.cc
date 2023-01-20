#include<stdio.h>
#include<stdlib.h>
#include<queue>
typedef struct _COORD{
  int x;
  int y;
  int time;
  int gram;
}coord;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int Matrix[101][101] = {};
int visited[101][101][2] = {};

int n,m,t;

int main(){
  std::queue<coord> a;

  scanf("%d%d%d",&n,&m,&t);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&Matrix[i][j]);
    }
  }

  a.push({1,1,0,0});
  visited[1][1][0] = 1;

  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    int time = now.time;
    int gram = now.gram;
    a.pop();

    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx <= 0 || ny <= 0 || nx > n || ny > m)continue;
      if(visited[nx][ny][gram])continue;

      if(nx == n && ny == m && time + 1 <= t){
        printf("%d",time + 1);
        return 0;
      }

      if(Matrix[nx][ny] == 0){
        a.push({nx, ny, time + 1, gram});
        visited[nx][ny][gram] = 1;
      }
      else if(Matrix[nx][ny] == 1){
        if(gram == 1){
          a.push({nx, ny, time + 1, gram});
          visited[nx][ny][gram] = 1;
        }
      }
      else if(Matrix[nx][ny] == 2){
        a.push({nx, ny, time + 1, 1});
        visited[nx][ny][1] = 1;
      }
    }
  }
  printf("Fail");
}