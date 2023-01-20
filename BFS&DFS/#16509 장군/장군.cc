#include<stdio.h>
#include<queue>

typedef struct _COORD{
  int x;
  int y;
  int dist;
}coord;

int n;
int x1,y1,ax,ay;
//맨 왼쪽 위, 맨 오른쪽 위, 맨 왼쪽 아래, 맨 오른쪽 아래
int dx[8] = {-3, -3, -2, -2, 2, 2, 3, 3};
int dy[8] = {-2, 2, -3, 3, -3, 3, -2, 2};

int bfs(int nowx, int nowy, int r, int c){
  std::queue <coord> a;
  if(nowx == r && nowy == c)
    return 0;
  int visited[10][10] = {};
  a.push({nowx, nowy, 0});
  visited[nowx][nowy] = 1;

  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    int dist = now.dist;
    a.pop();
    for(int i=0;i<8;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx > 9 || ny > 8)continue;
      if(visited[nx][ny] == 1)continue;
      if(i == 0 || i == 2){//왼쪽 위
        if(nx+1 == r && ny+1 == c)continue;
        if(nx+2 == r && ny+2 == c)continue;
      }
      else if(i == 1 || i == 3){//오른쪽 위
        if(nx+1 == r && ny-1 == c)continue;
        if(nx+2 == r && ny-2 == c)continue;
      }
      else if(i == 4 || i == 6){//왼쪽 아래
        if(nx-1 == r && ny+1 == c)continue;
        if(nx-2 == r && ny+2 == c)continue;
      }
      else if(i == 5 || i == 7){//오른쪽 아래
        if(nx-1 == r && ny-1 == c)continue;
        if(nx-2 == r && ny-2 == c)continue;
      }
      if(nx == r && ny == c){
        return dist + 1;
      }
      a.push({nx, ny, dist + 1});
      visited[nx][ny] = 1;
    }
  }
  return -1;
}
int main(){
  int x1,x2,y1,y2;
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  printf("%d",bfs(x1,y1,x2,y2));
  return 0;
}