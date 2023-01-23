#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 301

//큐 구조체
typedef struct COORD{
  int x;
  int y;
}coord;

//BFS를 실행하기 위한 큐
queue<coord> a;

//상 하 좌 우 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//지도의 상태 배열
int Matrix[MAX][MAX] = {};

//빙산 방문 체크 배열
int visited[MAX][MAX] = {};

//행, 열, 시간, 빙산의 수, 덩어리의 수
int n,m,t,ice = 0,mass = 0;

//BFS 실행 함수
void BFS(){
  //큐가 빌 때 까지 반복한다.
  while(!a.empty()){
    coord now = a.front();//큐에서 원솟값을 꺼낸다.
    int x = now.x;
    int y = now.y;
    a.pop();//다음 큐를 꺼내기 위해 pop한다.
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;                     //이미 방문된 곳이면 continue
      //빙산 주변이 바다이고 빙산이 녹았을때 0보다 더 줄어들지 않으면
      if(Matrix[nx][ny] == 0 && Matrix[x][y] - 1 > -1){
        Matrix[x][y]--;//빙산이 녹는다.
        //빙산이 다 녹았으면
        if(Matrix[x][y] == 0)
          ice--;//빙산의 수 - 1
      }
      //주변에 빙산이 있다면
      if(Matrix[nx][ny] > 0){
        a.push({nx, ny});    //큐에 push하고
        visited[nx][ny] = 1; //방문체크해준다.
      }
    }
  }
}

int main(){
  //행 열 입력
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];//지도의 상태를 입력받는다.
      //빙산이 입력되었다면
      if(Matrix[i][j] > 0)
        ice++;//빙산의 수 + 1
    }
  }
  //빙산의 수가 0이 되거나 두 덩어리이상으로 분리될 때까지 반복하는 반복문
  while(1){
    //빙산의 수가 0이 되면 0을 출력하고 반복문을 종료한다.
    if(ice == 0){
      cout << 0;
      break;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        //방문되지 않은 빙산이라면
        if(Matrix[i][j] > 0 && !visited[i][j]){
          a.push({i, j});     //큐에 그 빙산위치를 push하고
          visited[i][j] = 1;  //방문표시한다.
          BFS();              //BFS실행
          mass++;             //덩어리 + 1
        }
      }
    }
    //만약 두 덩어리 이상이라면 시간을 출력하고 반복문을 종료한다.
    if(mass > 1){
      cout << t;
      break;
    }
    t++;                                //시간이 흐른다.
    mass = 0;                           //다음 반복을 위해 덩어리를 초기화한다.
    memset(visited, 0, sizeof(visited));//다음 반복을 위해 방문체크배열을 초기화한다.
  }
  return 0;
}