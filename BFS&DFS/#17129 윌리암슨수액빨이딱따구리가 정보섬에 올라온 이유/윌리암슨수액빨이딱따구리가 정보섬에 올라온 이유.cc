#include<cstdio>
#include<queue>
#include<cstring>
#define Max 3001
using namespace std;

struct coord{
  int x;
  int y;
};

queue<coord> a;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char Matrix[Max][Max] = {};
int visited[Max][Max] = {};

int n, m;
int ax, ay;

int BFS(){
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;
      if(visited[nx][ny] != 0)continue;
      if(Matrix[nx][ny] == '3' || Matrix[nx][ny] == '4' || Matrix[nx][ny] == '5'){
        visited[nx][ny] = visited[x][y] + 1;
        ax = nx;
        ay = ny;
        return 1;
      }
      else if(Matrix[nx][ny] == '0'){
        a.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
      }
    }
  }
  return 0;
}

int main(){
  scanf("%d %d",&n, &m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf(" %1c",&Matrix[i][j]);
      if(Matrix[i][j] == '2'){
        Matrix[i][j] = '0';
        a.push({i, j});
        visited[i][j] = 1;
      }
    }
  }
  if(BFS())
    printf("TAK\n%d",visited[ax][ay] - 1);
  else
    printf("NIE");
}