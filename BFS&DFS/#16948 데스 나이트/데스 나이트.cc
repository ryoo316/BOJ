#include<stdio.h>
#include<queue>

typedef struct _COORD{
  int x;
  int y;
  int dist;
}coord;

int n;
int x1,y1,ax,ay;

// (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int bfs(int nowx, int nowy, int r, int c){
  std::queue <coord> a;
  if(nowx == r && nowy == c)
    return 0;
  int visited[301][301] = {};
  a.push({nowx, nowy, 0});
  visited[nowx][nowy] = 1;

  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    int dist = now.dist;
    a.pop();
    for(int i=0;i<6;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1)continue;
      if(visited[nx][ny] == 1)continue;
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
  scanf("%d",&n);
  scanf("%d%d%d%d",&x1,&y1,&ax,&ay);
  printf("%d\n",bfs(x1, y1, ax, ay));
  return 0;
}