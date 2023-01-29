#include<iostream>
#include<queue>
#include<cstring>
#define MAX 501
using namespace std;

typedef struct COORD{
  int x;
  int y;
}coord;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int n, m;
int sx,sy;

int visited[MAX][MAX] = {};

queue<coord> a;

int BFS(){
  a.push({sx, sy});
  visited[sx][sy] = 1;
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<8;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
      if(visited[nx][ny])continue;
      a.push({nx, ny});
      visited[nx][ny] = visited[x][y] + 1;
    }
  }
  return -1;
}

int main(){
  cin >> n >> m;
  cin >> sx >> sy;
  BFS();
  for(int i=1;i<=m;i++){
    int a, b;
    cin >> a >> b;
    cout << visited[a][b] - 1<< " ";
  }
}