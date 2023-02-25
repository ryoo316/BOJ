#include<iostream>
#include<queue>
#define Max 51
using namespace std;
//구조체
struct coord{
  int x;
  int y;
  int key;
};
//기본 미로 배열
char Matrix[Max][Max] = {};
//방문체크(비트마스킹) 51*51*64 = 166,464Byte = 0.16MB
bool visited[Max][Max][1<<6];
//행, 열, 시작위치
int h, w, sx, sy;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//BFS실행함수
int BFS(){
  queue<coord> Q;
  Q.push({sx, sy, 0});
  visited[sx][sy][0] = true;
  int t = 1;//시간
  while(!Q.empty()){
    int qsize = Q.size();
    //큐 사이즈만큼 돌린후 시간이 지난다.
    for(int k=0;k<qsize;k++){
      coord cur = Q.front();
      int x = cur.x;
      int y = cur.y;
      Q.pop();
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int key = cur.key;//nx, ny위치로 갈때 key값을 꺼내준다.
        if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
        if(Matrix[nx][ny] == '#')continue; //벽이면 continue

        //탈출구에 도착하면 시간을 출력한다.
        if(Matrix[nx][ny] == '1')
          return t;

        //열쇠가 있으면
        if('a' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'f')
          key |= (1 << (Matrix[nx][ny] - 'a'));//키를 저장한다.
        if(visited[nx][ny][key])continue;  //방문했었으면 continue
        //문이 있다면
        if('A' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'F')
          if(((1 << (Matrix[nx][ny] - 'A')) & key) == 0)continue;//그 문을 열 열쇠가 없으면 continue

        //큐에 넣고 방문체크
        Q.push({nx, ny, key});
        visited[nx][ny][key] = true;
      }
    }
    t++;//시간 지남
  }
  return -1;
}

void Input(){
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
      if(Matrix[i][j] == '0'){
        sx = i;
        sy = j;
        Matrix[i][j] = '.';
      }
    }
  }
}

void Solution(){
  cout << BFS();
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