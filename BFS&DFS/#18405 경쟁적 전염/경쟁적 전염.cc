#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001

typedef struct COORD{
  int x;
  int y;
}coord;

queue<coord> a;

int Matrix[MAX][MAX] = {};

int n,m;
int s,x,y;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void BFS(int t){
  while(!a.empty() && t--){
    int qsize = a.size();
    for(int k=0;k<qsize;k++){
      coord now = a.front();
      int x = now.x;
      int y = now.y;
      a.pop();
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
  
        if(Matrix[nx][ny] == 0){
          a.push({nx, ny});
          Matrix[nx][ny] = Matrix[x][y];
        }
      }
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> Matrix[i][j];
    }
  }
  for(int k=1;k<=m;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(k == Matrix[i][j]){
          a.push({i, j});
        }
      }
    }
  }
  cin >> s >> x >> y;
  BFS(s);
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     cout << Matrix[i][j];
  //   }
  //   cout << "\n";
  // }
  cout << Matrix[x][y];
}