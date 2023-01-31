#include<iostream>
#include<queue>
#include<cstring>
#define Max 1001
using namespace std;

struct coord{
  int x;
  int y;
};

queue<coord> a;

int Matrix[Max][Max] = {};
int visited[Max][Max] = {};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n, m;

void BFS(){
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;
      if(visited[nx][ny] != -1)continue;
      if(Matrix[nx][ny] == 1){
        a.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
      }
    }
  }
}

int main(){
  memset(visited, -1, sizeof(visited));
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
      if(Matrix[i][j] == 2){
        a.push({i, j});
        visited[i][j] = 0;
      }
    }
  }
  BFS();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(Matrix[i][j] == 0 && visited[i][j] == -1)
        cout << 0 << " ";
      else if(Matrix[i][j] == 1 && visited[i][j] == -1)
        cout << -1 << " ";
      else
        cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}