#include<iostream>
#include<queue>
#define Max 2002
using namespace std;

struct coord{
  int x;
  int y;
};

queue<coord> a;

//상 하 좌 우 탐색 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//행, 열
int h, w;

//미로 맵
char maze[Max][Max] = {};
//방문체크 배열
int visited[Max][Max] = {};

//dead end filling 알고리즘
void dead_end_filling(){
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();//큐에서 위치 값을 꺼낸다.
    int x = now.x;
    int y = now.y;
    a.pop();              //큐 pop
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;      //이미 방문했었으면 continue
      if(maze[nx][ny] == '+')continue;  //막힌 벽이면 continue
      int cnt = 0;
      //몇갈래로 나눠지는지 확인하는 반복문
      for(int j=0;j<4;j++){
        int xx = nx + dx[j];
        int yy = ny + dy[j];
        if(xx < 1 || yy < 1 || xx > h || yy > w)continue;//범위 벗어나면 continue
        if(visited[xx][yy])continue;//이미 방문했었으면 continue
        //주변에 빈 곳이 있으면 cnt + 1
        if(maze[xx][yy] == '.')
          cnt++;
      }
      if(cnt > 1)continue; //2갈래이상으로 나눠지면 continue
      maze[nx][ny] = '@';  //사용하지않은 길 표시
      a.push({nx, ny});    //큐에 다음 위치를 넣어준다.
      visited[nx][ny] = 1; //방문표시
    }
  }
}

//입력 받는 함수
void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> maze[i][j];
    }
  }
}

//문제풀기
void solve(){
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(maze[i][j] == '.'){
        int cnt = 0;
        for(int k=0;k<4;k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
          if(maze[nx][ny] == '+')
            cnt++;
        }
        //주변이 3개이상 벽으로 막혀있다면 큐에 넣어준다.
        if(cnt >= 3){
          maze[i][j] = '@';
          a.push({i, j});
          visited[i][j] = 1;
        }
      }
    }
  }
  dead_end_filling();
}

int main(){
  
  input();
  solve();

  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cout << maze[i][j];
    }
    cout << "\n";
  }
  return 0;
}