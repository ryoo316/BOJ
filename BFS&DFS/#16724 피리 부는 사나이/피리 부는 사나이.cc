#include<iostream>
#define Max 1001
using namespace std;

int h, w, cyc = 0, cnt = 1;
int visited[Max][Max] = {};

char Matrix[Max][Max] = {};

void DFS(int sx, int sy){
  int nx = sx, ny = sy;
  visited[sx][sy] = cnt;//방문체크
  //방향
  if(Matrix[sx][sy] == 'U')
    nx--;
  else if(Matrix[sx][sy] == 'D')
    nx++;
  else if(Matrix[sx][sy] == 'L')
    ny--;
  else
    ny++;

  if(visited[nx][ny] != 0){
    if(visited[nx][ny] == cnt)//cnt사이클
      cyc++;
    else
      return;
  }
  else{
    DFS(nx, ny); 
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
      if(!visited[i][j]){
        DFS(i, j);
        cnt++;
      }
    }
  }
  cout << cyc;
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

  return 0;
}