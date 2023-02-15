#include<iostream>
#include<queue>
#define Max 51
using namespace std;

struct coord{
  int x;
  int y;
};

int h, w, res = -123123;

char Matrix[Max][Max] = {};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
    }
  }
}

int BFS(int sx, int sy){
  queue<coord> q;
  int visited[Max][Max] = {};
  visited[sx][sy] = 0;
  q.push({sx, sy});
  int max1 = -123123;
  while(!q.empty()){
    coord cur = q.front();
    int x = cur.x;
    int y = cur.y;
    q.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
      if(visited[nx][ny] != 0)continue;
      if(nx == sx && ny == sy)continue;
      if(Matrix[nx][ny] == 'L'){
        q.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
        max1 = max(max1, visited[nx][ny]);
      }
    }
  }
  return max1;
}

void solve(){
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(Matrix[i][j] == 'L'){
        int m = BFS(i, j);
        res = max(m, res);
      }
    }
  }
}

int main(){
  input();
  
  solve();

  cout << res;
  return 0;
}