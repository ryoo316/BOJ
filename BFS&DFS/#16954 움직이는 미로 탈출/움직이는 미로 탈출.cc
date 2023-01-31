#include<iostream>
#include<queue>
#include<cstring>
#define Max 9
using namespace std;

//큐 구조체
struct coord{
  int x;
  int y;
};

//인접한 한 칸 또는 대각선 방향으로 인접한 한 칸
int dx[9] = {1,0,-1,0,-1,-1,1,1,0};
int dy[9] = {0,1,0,-1,1,-1,1,-1,0};

//체스판의 상태 배열
char Matrix[Max][Max] = {};
//방문 체크 배열
int visited[Max][Max] = {};

queue<coord> a;

int BFS(){
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    int len = a.size();//시간
    memset(visited, 0, sizeof(visited));
    for(int k=0;k<len;k++){
      coord now = a.front();//큐에서 값 꺼내기
      int x = now.x;
      int y = now.y;
      a.pop();
      for(int i=0;i<9;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > 8 || ny > 8)continue;//범위 벗어나면 continue
        if(Matrix[nx][ny] == '#' || visited[nx][ny])continue;
        if(nx >= 1 && Matrix[nx-1][ny] == '#')continue;//움직이려는 칸위에 벽이 있으면 안된다.
        //가장 오른쪽 윗칸에 도착하면
        if(nx == 1 && ny == 8){
          return 1;
        }
        a.push({nx, ny});            //큐에 넣기
        visited[nx][ny] = 1;         //방문체크
      }
    }
    //벽이 아래로 움직이도록하는 반복문
    for(int i=8;i>=1;i--){
      for(int j=1;j<=8;j++){
        if(Matrix[i][j] == '#'){
          Matrix[i][j] = '.';
          if(i + 1 > 8)continue;
          Matrix[i+1][j] = '#';
        }
      }
    }
  }
  return 0;
}

int main(){
  
  //체스판의 상태를 입력
  for(int i=1;i<=8;i++){
    for(int j=1;j<=8;j++){
      cin >> Matrix[i][j];
    }
  }
  //플레이어를 넣어준다.
  Matrix[8][1] = '&';
  visited[8][1] = 1;
  a.push({8, 1});
  //1을 반환하면 1출력 0을 반환하면 0출력
  if(BFS())
    cout << 1;
  else
    cout << 0;
  // for(int i=1;i<=8;i++){
  //   for(int j=1;j<=8;j++){
  //     cout << Matrix[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  return 0;
}