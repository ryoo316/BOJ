#include<stdio.h>

int map[51][51] = {};

int visited[51][51] = {};

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};

int w,h;

int cnt = 0;
void dfs(int x,int y)
{
  visited[x][y] = 1;

  for(int i=0;i<8;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(visited[nx][ny] == 1)continue;
    if(nx >= 1 && ny >= 1 && nx <= h && ny <= w){
      if(map[nx][ny] == 1){
        dfs(nx,ny);
      }
    }
  }
}
int main()
{
  while(1){
    scanf("%d%d",&w,&h);
    if(w==0&&h==0) return 0;
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        scanf("%d",&map[i][j]);
      }
    }
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        if(visited[i][j])continue;
        if(map[i][j] == 1){
          dfs(i,j);
          cnt++;
        }
      }
    }
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        visited[i][j] = 0;
      }
    }
    printf("%d\n",cnt);
    cnt = 0;
  }
}