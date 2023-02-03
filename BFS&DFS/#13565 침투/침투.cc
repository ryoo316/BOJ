#include<iostream>
#include<queue>
#define Max 1001
using namespace std;

struct coord{
  int x;
  int y;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char Matrix[Max][Max] = {};
int visited[Max][Max] = {};

queue<coord> a;

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
      if(visited[nx][ny])continue;
      if(Matrix[nx][ny] == '0'){
        visited[nx][ny] = 1;
        a.push({nx, ny});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
    }
  }
  for(int j=1;j<=m;j++){
    if(Matrix[1][j] == '0'){
      a.push({1, j});
      visited[1][j] = 1;
    }
  }
  BFS();
  int flag = 0;
  for(int j=1;j<=m;j++){
    if(visited[n][j] == 1){
      flag = 1;
      break;
    }
  }
  if(flag)
    cout << "YES";
  else
    cout << "NO";
}