#include<stdio.h>
#include<queue>
#include<string.h>

typedef struct _COORD{
  int x;
  int y;
}coord;

std::queue<coord> a;

int Matrix[101][101] = {};
int visited[101][101] = {};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,res = 0;
int time = -1;

int bfs(int x, int y){
  a.push({1,1});
  visited[1][1] = 1;
  int cnt = 0;
  time++;
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx <= 0 || ny <= 0 || nx > n || ny > m)continue;
      if(visited[nx][ny])continue;

      if(Matrix[nx][ny] == 0){//치즈가 없으면 이동
        a.push({nx, ny});
        visited[nx][ny] = 1;
      }
      else if(Matrix[nx][ny] == 1){//치즈가 있으면 치즈를 없애고 cnt++
        Matrix[nx][ny] = 0;
        visited[nx][ny] = 1;
        cnt++;
      }
    }
  }
  if(cnt == 0){
    printf("%d\n%d", time, res);
    return 1;
  }
  else{
    res = cnt;
    return 0;
  }
}

int main(){
  scanf("%d%d",&n,&m);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&Matrix[i][j]);
    }
  }
  while(1){
    if(bfs(1,1) == 1)
      break;
    memset(visited, 0, sizeof(visited));
  }
  return 0;
}