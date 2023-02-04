#include<iostream>
#include<cstring>
#include<queue>
#define Max 1001
using namespace std;

//큐 구조체
struct coord{
  int x;
  int y;
};

//상 하 좌 우 탐색
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//기본 맵 배열
char Matrix[Max][Max] = {};
//방문체크 and 거리 배열
int visited[Max][Max] = {};

//맵 높이, 너비, 치즈공장의 수, 답, 쥐의 체력;
int h, w, n, ans = 0, stamina = 1;
//쥐의 위치, 치즈를 먹기위한 최소 거리
int s_x, s_y, min_x, min_y;

//치즈를 먹기위한 최소거리를 찾는 BFS실행 함수
int BFS(int r, int c){
  memset(visited, -1, sizeof(visited));//visited배열 초기화
  queue<coord> a;    //큐
  visited[r][c] = 0; //지금 위치거리를 0으로 해준다.
  a.push({r, c});    //큐에다 지금 위치를 넣기
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();    //큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;//범위 벗어나면 continue
      if(visited[nx][ny] != -1)continue;               //이미 방문한 곳이면 continue
      if(Matrix[nx][ny] == 'X')continue;               //장애물이면 continue
      
      //만약 같다면
      if(Matrix[nx][ny] - '0' == stamina){
        //최소거리를 찾은거니 return 1을 해준다.
        visited[nx][ny] = visited[x][y] + 1;
        min_x = nx;
        min_y = ny;
        return 1;
      }
      a.push({nx, ny});
      visited[nx][ny] = visited[x][y] + 1;
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //입력
  cin >> h >> w >> n;
  
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> Matrix[i][j];
      if(Matrix[i][j] == 'S'){//지금 쥐의 위치
        s_x = i;
        s_y = j;
      }
    }
  }

  for(int i = 1; i <= n; i++){
    BFS(s_x, s_y);
    stamina++;
    ans += visited[min_x][min_y];
    s_x = min_x;
    s_y = min_y;
  }
  cout << ans;//답 출력
  return 0;
}