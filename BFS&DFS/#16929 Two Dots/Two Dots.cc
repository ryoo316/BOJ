#include<iostream>
#include<queue>
#include<cstring>
#define Max 51
using namespace std;

int h, w;

char Matrix[Max][Max] = {};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool visited[Max][Max] = {};
bool flag = 0;

int rx, ry;
char c;

void DFS(int sx, int sy, int n){
  if(flag)
    return;
  for(int i=0;i<4;i++){
    int nx = sx + dx[i];
    int ny = sy + dy[i];
    if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
    if(c != Matrix[nx][ny])continue;
    if(visited[nx][ny]){
      if(nx == rx && ny == ry && n >= 4){
        flag = true;
        return;
      }
    }
    else{
      visited[nx][ny] = true;
      DFS(nx, ny, n+1);
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
      memset(visited, 0, sizeof(visited));
      c = Matrix[i][j];
      rx = i;
      ry = j;
      visited[i][j] = true;
      DFS(i, j, 1);
      if(flag)
        break;
    }
  }
}

void Solve(){
  Input();
  Solution();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  Solve();

  if(flag)
    cout << "Yes";
  else
    cout << "No";
  
  return 0;
}