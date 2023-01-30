#include<iostream>
#include<queue>
#include<cstring>
#define Max 21
#define Max_val 99999
using namespace std;

/*
더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.

먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.

거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다
*/

//좌표 구조체
struct spector{
  int x;  //x 좌표
  int y;  //y 좌표
};

//상 하 좌 우 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//공간 배열
int Matrix[Max][Max] = {};
//방문 체크 배열
int visited[Max][Max] = {};

//공간 크기, 최단거리, 최단_x, 최단_y, 엄마 상어의 도움을 받지 않고 물고기를 먹을 수 있는 최단 시간, 물고기 수
int n, min_dist, min_x, min_y, ans_dist = 0, fish_cnt = 0;
//상어의 경험치, 상어의 위치, 상어의 크기
int exp = 0, s_x, s_y, s_size = 2;

//BFS실행 함수
void BFS(int sx, int sy){
  queue<spector> a;
  a.push({sx, sy});
  visited[sx][sy] = 0;
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    spector now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      //범위 벗어나면 continue
      if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
      //이미 방문한 곳이라면 continue
      if(visited[nx][ny] != -1)continue;
      //상어의 크기보다 큰 물고기면 continue
      if(Matrix[nx][ny] > s_size)continue;
      //거리 계산
      visited[nx][ny] = visited[x][y] + 1;
      a.push({nx, ny});
      
      //먹을수 있는 물고기이면
      if(Matrix[nx][ny] != 0 && Matrix[nx][ny] < s_size){
        //최단 거리를 갱신해준다.
        if(min_dist > visited[nx][ny]){
          min_x = nx;
          min_y = ny;
          min_dist = visited[nx][ny];
        }
        //만약 최단 거리가 같다면
        else if(min_dist == visited[nx][ny]){
          //가장 왼쪽에 있는 물고기
          if(min_x == nx){
            if(min_y > ny){
              min_x = nx;
              min_y = ny;
            }
          }
          //가장 위쪽에 있는 물고기
          else if(min_x > nx){
            min_x = nx;
            min_y = ny;
          }
        }
      }
    }
  }
}

int main(){
  //공간 크기 입력
  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> Matrix[i][j];
      //상어의 위치를 입력받으면
      if(Matrix[i][j] == 9){
        //상어의 위치 저장
        s_x = i;
        s_y = j;
        //상어의 위치는 0으로 비워준다.
        Matrix[i][j] = 0;
      }
      //물고기의 위치를 입력받으면
      else if(0 < Matrix[i][j] && Matrix[i][j] < 7){
        //물고기의 수 증가
        fish_cnt++;
      }
    }
  }
  memset(visited, -1, sizeof(visited));
  while(1){
    //더 이상 물고기가 없다면 break해준다.
    if(fish_cnt == 0)
      break;
    //값들을 초기화해준다.
    min_x = Max_val;
    min_y = Max_val;
    min_dist = Max_val;
    //BFS 실행
    BFS(s_x, s_y);

    //먹을 수 있는 물고기가 없다면 break해준다.
    if(min_x == Max_val && min_y == Max_val)
      break;
    else{
      //거리 갱신
      ans_dist += visited[min_x][min_y];
      //물고기를 먹었으므로 그 위치를 빈곳으로 바꿔준다.
      Matrix[min_x][min_y] = 0;
      //상어의 경험치 up
      exp++;
      //물고기의 수 감소
      fish_cnt--;
      //상어의 경험치가 지금 상어의 크기면
      if(exp == s_size){
        //상어의 크기 증가
        s_size++;
        //경험치 초기화
        exp = 0;
      }
    }
    //상어의 위치 갱신
    s_x = min_x;
    s_y = min_y;
    //방문 체크 배열 초기화
    memset(visited, -1, sizeof(visited));
  }
  //답 출력
  cout << ans_dist;
  return 0;
}