#include<iostream>
#include<queue>
#define MAX 201
using namespace std;

//큐 구조체
typedef struct COORD{
  int x;    //x 좌표
  int y;    //y 좌표
  int dist; //거리
  int skill;//말로 움직일 수 있는 동작 수
}coord;

//BFS를 하기위한 큐
queue<coord> a;

//말 동작수, 열, 행
int k,w,h;

//지도의 상태 배열
int Matrix[MAX][MAX] = {};

//방문 체크 배열
int visited[MAX][MAX][31] = {};

//상 하 좌 우 움직이는 배열
int dx1[4] = {1,-1,0,0};
int dy1[4] = {0,0,1,-1};

//말로 움직이는 배열
int dx2[8] = {-1,-2,-2,-1,1,2,2,1};
int dy2[8] = {-2,-1,1,2,2,1,-1,-2};

//BFS 실행 함수
int BFS(){
  a.push({1, 1, 0, k});//큐에 위치와 말 동작수를 넣어준다.
  visited[1][1][k] = 1;//처음 위치 방문체크
  while(!a.empty()){//큐가 빌때까지 반복한다.
    coord now = a.front();//큐에서 값을 꺼내준다.
    int x = now.x;
    int y = now.y;
    int dist = now.dist;
    int skill = now.skill;
    a.pop();//다음 큐를 위해 pop을 해준다.
    for(int i=0;i<4;i++){//상 하 좌 우
      int nx = x + dx1[i];
      int ny = y + dy1[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;//범위 벗어나면 continue
      if(visited[nx][ny][skill])continue;//방문 되었었다면 continue
      if(nx == h && ny == w)//도착하면 리턴
        return dist + 1;
      if(Matrix[nx][ny] == 0){//주변이 평지면 이동
        a.push({nx, ny, dist + 1, skill});
        visited[nx][ny][skill] = 1;
      }
    }
    for(int i=0;i<8;i++){//말 로이동
      int nx = x + dx2[i];
      int ny = y + dy2[i];
      if(skill == 0)continue;//이미 다 쓴 상태면 continue
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;//범위 벗어나면 continue
      if(visited[nx][ny][skill])continue;//방문되었었다면 continue
      if(nx == h && ny == w)//도착하면 리턴
        return dist + 1;
      if(visited[nx][ny][skill-1] == 0 && Matrix[nx][ny] == 0){//방문되있지않고 평지면
        a.push({nx, ny, dist + 1, skill - 1});
        visited[nx][ny][skill - 1] = 1;
      }
    }
  }
  //큐가 빌때까지 도착못했다면 -1반환
  return -1;
}

int main(){
  //말로 움직일 수 있는 동작수
  cin >> k;
  //열, 행
  cin >> w >> h;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      //지도의 상태 입력
      cin >> Matrix[i][j];
    }
  }
  if(w == 1 && h == 1)//예외처리
    cout << 0;
  else
    cout << BFS();//BFS 실행
  return 0;
}