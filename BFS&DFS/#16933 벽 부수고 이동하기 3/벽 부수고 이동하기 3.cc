#include<stdio.h>
#include<queue>
typedef struct{
  int x;
  int y;
  int dist;
  int cnt;
}coord;

int Matrix[1005][1005] = {};

int visited[1005][1005][11] = {};
//방문체크 (벽 부쉈는지 안 부쉈는지도 방문 체크)
int n,m,k;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%1d",&Matrix[i][j]);
    }
  }
  if(n == 1 && m == 1 && Matrix[1][1] == 0){
  printf("1");
  return 0;
  }
  std::queue <coord> a;
  a.push({1,1,1,0});
  visited[1][1][0] = 1;

  while(!a.empty()){
    coord now = a.front();
    int dist = now.dist;
    int x = now.x;
    int y = now.y;
    int cnt = now.cnt;
    a.pop();
    //가장 처음에 이동할 때가 낮이다.
    //한 번 이동할 때마다 밤낮이 바뀐다.
    //이동하지 않고 같은 칸에 머무르는 것도 가능하지만 낮 밤이 바뀌게 된다.
    //dist가 홀수면 낮, 짝수면 밤으로 본다.
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if(nx <= 0 || ny <= 0 || nx > n || ny > m)continue;
      if(visited[nx][ny][cnt])continue;
      if(nx == n && ny == m){
        printf("%d",dist+1);
        return 0;
      }
      if(Matrix[nx][ny] == 1){
        if(cnt >= k)continue;//부술 수 없으면 continue
        if(dist % 2 == 1 && visited[nx][ny][cnt + 1] == 0){
          a.push({nx, ny, dist + 1, cnt + 1});
          visited[nx][ny][cnt + 1] = 1;
        }
        else if(dist % 2 == 0 && visited[nx][ny][cnt + 1] == 0){
          a.push({x, y, dist + 1, cnt});
          visited[x][y][cnt] = 1;
        }
      }
      else{
        a.push({nx, ny, dist + 1, cnt});
        visited[nx][ny][cnt] = 1;
      }
    }
  }
  printf("-1");
}
