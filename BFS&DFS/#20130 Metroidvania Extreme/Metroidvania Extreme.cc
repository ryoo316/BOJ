#include<iostream>
#include<vector>
#include<queue>
#define Max 205
using namespace std;
//구조체
struct coord{
  int x;
  int y;
};
//행, 열, 시작 위치, 움직임횟수
int h, w, sx, sy;
//기본 지도 배열
char Matrix[Max][Max] = {};
//방문 체크 배열
bool visited[Max][Max] = {};
//열쇠 (비트마스킹)
int key = 0;
//움직인 위치를 저장하기위한 벡터
vector<coord> V;
//상 하 좌 우 움직임
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//BFS실행함수
void BFS(){
  queue<coord> Q;
  Q.push({sx, sy});
  visited[sx][sy] = true;
  V.push_back({sx, sy});
  queue<coord> door[27];//문 위치 저장
  
  while(!Q.empty()){
    coord cur = Q.front();
    int x = cur.x;
    int y = cur.y;
    Q.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(Matrix[nx][ny] == '#')continue;               //벽 체크
      if(visited[nx][ny])continue;                     //방문 체크
      //목적지에 도착하면 이 함수에서 나가기
      if(Matrix[nx][ny] == '!'){
        V.push_back({nx, ny});//위치 저장
        return;
      }
      if('A' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'Z'){
        //열쇠가 없다면 그 문위치를 저장해놓기
        if(((1 << (Matrix[nx][ny] - 'A')) & key) == 0){
          door[Matrix[nx][ny] - 'A'].push({nx, ny});
          continue;
        }
      }
      //이동
      Q.push({nx, ny});
      visited[nx][ny] = true;
      V.push_back({nx, ny});
      
      //열쇠이면 열쇠를 먹기
      if('a' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'z'){
        key |= 1 << (Matrix[nx][ny] - 'a');//열쇠 저장
        //그 열쇠가 필요한 문이 전에 있었다면
        while(!door[Matrix[nx][ny] - 'a'].empty()){
          coord doorcur = door[Matrix[nx][ny] - 'a'].front();
          int doorx = doorcur.x;
          int doory = doorcur.y;
          door[Matrix[nx][ny] - 'a'].pop();
          if(visited[doorx][doory])continue;
          
          //그 문으로 이동
          Q.push({doorx, doory});
          V.push_back({doorx, doory});
          visited[doorx][doory] = true;
        }
      }
    }
  }
}

void Input(){
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
      if(Matrix[i][j] == '@'){
        sx = i;
        sy = j;
        Matrix[i][j] = '*';
      }
    }
  }
}

void Solution(){
  BFS();
  cout << V.size() << "\n";
  for(int i=0;i<V.size();i++){
    int x = V[i].x;
    int y = V[i].y;
    cout << x << " " << y << "\n";
  }
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