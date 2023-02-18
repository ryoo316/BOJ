#include<iostream>
#include<queue>
#define Max 1001
using namespace std;

struct coord{
  int x;
  int y;
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int Matrix[Max][Max] = {};
bool visited[Max][Max] = {};

int h, w, cnt = 0;

void BFS(int sx, int sy){
  queue<coord> Q;
  Q.push({sx, sy});
  visited[sx][sy] = true;
  while(!Q.empty()){
    coord cur = Q.front();
    int x = cur.x;
    int y = cur.y;
    Q.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w){
        if(i == 0 && !Matrix[h][ny]){
          if(visited[h][ny])continue;
          Q.push({h, ny});
          visited[h][ny] = true;
        }
        else if(i == 1 && !Matrix[1][ny]){
          if(visited[1][ny])continue;
          Q.push({1, ny});
          visited[1][ny] = true;
        }
        else if(i == 2 && !Matrix[nx][w]){
          if(visited[nx][w])continue;
          Q.push({nx, w});
          visited[nx][w] = true;
        }
        else if(i == 3 && !Matrix[nx][1]){
          if(visited[nx][1])continue;
          Q.push({nx, 1});
          visited[nx][1] = true;
        }
      }
      else{
        if(Matrix[nx][ny])continue;
        if(visited[nx][ny])continue;
        Q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}

void Input(){
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
    }
  }
}

void Solution(){
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(visited[i][j])continue;
      if(Matrix[i][j])continue;
      BFS(i, j);
      cnt++;
    }
  }
  cout << cnt;
}

void Solve(){
  Input();
  Solution();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  Solve();

  return 0;
}