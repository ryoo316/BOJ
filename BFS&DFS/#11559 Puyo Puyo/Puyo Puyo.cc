#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//큐 구조체
struct coord{
  int x;
  int y;
};

//상 하 좌 우 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//맵 상태 배열
char Matrix[13][7] = {};
//방문체크 배열
int visited[13][7] = {};

//답, 폭발되었는지 확인하는 변수
int ans = 0, is_explosion = 0;

//폭발시키는 함수
void Explosion(int s_x, int s_y){
  queue<coord> a;
  char c = Matrix[s_x][s_y];

  int visited1[13][7] = {};
  a.push({s_x, s_y});
  visited1[s_x][s_y] = 1;
  Matrix[s_x][s_y] = '.';
  
  while(!a.empty()){
    coord now = a.front();                  //큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();                                //큐 pop
    visited1[x][y] = 0;
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > 12 || ny > 6)continue;    //범위 벗어나면 continue
      if(Matrix[nx][ny] != c || visited1[nx][ny])continue;  //이미 방문했으면 continue
      a.push({nx, ny});
      visited1[nx][ny] = 1;
      Matrix[nx][ny] = '.';
    }
  }
}

//BFS함수
void BFS(int s_x, int s_y){
  
  int cnt = 1;                  //블럭 몇개가 연쇄되어있는지 확인하는 변수
  queue<coord> a;
  
  visited[s_x][s_y] = 1;        //지금 위치 방문 체크
  a.push({s_x, s_y});           //지금 위치 큐에 넣기

  //큐가 빌 때까지 반복
  while(!a.empty()){
    coord now = a.front();      //큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();                    //큐 pop
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > 12 || ny > 6)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;                      //이미 방문했으면 continue
      if(Matrix[nx][ny] == Matrix[x][y]){               //같은 블럭이면
        a.push({nx, ny});
        visited[nx][ny] = 1;
        cnt++;                                          //연쇄 + 1
      }
    }
  }
  //블럭 4개이상이 연쇄되어있으면
  if(cnt >= 4){
    Explosion(s_x, s_y);     //폭발
    is_explosion = 1;        //폭발됨
  }
}

//중력으로 인해 블럭이 아래로 내려가도록하는 함수
void move_down(){
  int j = 1;//열마다 확인
  while(1){
    for(int i=12;i>=1;i--){
      if(Matrix[i][j] != '.')continue;
      for(int k=1;k<=i;k++){
        if(Matrix[k][j] != '.'){
          char c = Matrix[i][j];
          Matrix[i][j] = Matrix[k][j];
          Matrix[k][j] = c;
        }
      }
    }
    j++;
    if(j == 7)
      break;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //맵 상태 입력받기
  for(int i=1;i<=12;i++){
    for(int j=1;j<=6;j++){
      cin >> Matrix[i][j];
    }
  }
  //폭발이 안 될때까지 반복해준다.
  while(1){
    for(int i=1;i<=12;i++){
      for(int j=1;j<=6;j++){
        if(visited[i][j])continue;
        if(Matrix[i][j] == 'R' || Matrix[i][j] == 'G' || Matrix[i][j] == 'B'){
          BFS(i, j);
        }
        if(Matrix[i][j] == 'P' || Matrix[i][j] == 'Y'){
          BFS(i, j);
        }
      }
    }
    //폭발되었으면
    if(is_explosion){
      ans++;//답 + 1
      move_down();//내려가도록한다.
    }
    //폭발이 안됐으면 break해준다.
    else
      break;
    is_explosion = 0;
    memset(visited, 0, sizeof(visited));//방문체크 배열 초기화
  }
  
  // for(int i=1;i<=12;i++){
  //   for(int j=1;j<=6;j++){
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // for(int i=1;i<=12;i++){
  //   for(int j=1;j<=6;j++){
  //     cout << Matrix[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << ans;
}