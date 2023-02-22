#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define Max 101
using namespace std;
//구조체
struct coord{
  int x;
  int y;
};
//맵 크기, 스위치개수, 불을 킬 수 있는 방의 수
int n, m, room = 0;
//기본 지도 배열
char Matrix[Max][Max] = {};
//방문 체크 배열
bool visited[Max][Max] = {};
//불을 켜져있는지 확인하는 배열
bool light[Max][Max] = {};
//상 하 좌 우 움직임
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//스위치위치 저장
queue<coord> switch_cd[Max][Max];

//BFS실행함수
void BFS(){
  queue<coord> Q;
  Q.push({1, 1});
  visited[1][1] = true;
  light[1][1] = true;

  //방문할 수 있는 거리에 있었으나 불이 켜지지 않았어서 방문하지 못한곳을 따로 저장해주는 배열)(후에 켜질 가능성이 있는 곳
  bool Save_visit[Max][Max] = {};
  
  while(!Q.empty()){
    coord cur = Q.front();
    int x = cur.x;
    int y = cur.y;
    Q.pop();
    //지금위치에 있는 스위치 작동시키기
    while(!switch_cd[x][y].empty()){
      coord scur = switch_cd[x][y].front();
      int x1 = scur.x;
      int y1 = scur.y;
      switch_cd[x][y].pop();
      light[x1][y1] = true;
      //만약 켜지는 곳이 전에 방문할 수 있었으나 불이 켜지지않아서 못 이동하던 곳이었으면 큐에 넣어준다.
      if(Save_visit[x1][y1]){
        Q.push({x1, y1});
        visited[x1][y1] = true;
        Save_visit[x1][y1] = false;//방문했으니 false처리해준다.
      }
    }
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
      if(visited[nx][ny])continue;
      //방문할수 있는 거리(현재 있는 셀과 대상셀이 맨하탄 거리 기준 1)에 있었으나 불이 켜지지 않았어서 방문하지 못한곳
      if(!light[nx][ny]){
        Save_visit[nx][ny] = true;
        continue;
      }
      Q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
}

void Input(){
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    switch_cd[x][y].push({a, b});
  }
}

void Solution(){
  BFS();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(light[i][j])
        room++;
    }
  }
  cout << room;
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