#include<bits/stdc++.h>
#define Max 1001
using namespace std;

//큐 구조체
struct coord{
  int x;
  int y;
};

//상 하 좌 우 탐색 배열
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//행, 열, 최대 영역, 영역을 세는 변수, 그룹번호
int n, m, max_ans = -123123, d = 1, g = 0;

//맵 배열
int Matrix[Max][Max] = {};
//방문체크 배열
int visited[Max][Max] = {};
//그룹화하기
int group_member[Max][Max] = {};
//그 그룹의 1의 개수
int group_cnt[1000001] = {};
bool check[1000001] = {};
//BFS탐색 함수
void BFS(int s_x, int s_y){
  queue<coord> a;                     //큐 선언
  visited[s_x][s_y] = 1;              //지금 위치 방문표시
  a.push({s_x, s_y});                 //지금 위치 큐에 넣기
  group_member[s_x][s_y] = g;         //그룹화
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();//큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();              //큐 pop
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;                     //방문했었으면 continue
      //주변이 1이라면
      if(Matrix[nx][ny] == 1){
        a.push({nx, ny});
        visited[nx][ny] = 1;
        group_member[nx][ny] = g;        //그룹화한다.
        d++;                             //영역추가
      }
    }
  }
}

//입력받는 함수
void input(){
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
    }
  }
}

//문제 푸는 로직함수
void solve(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(visited[i][j])continue;//이미 방문했으면 continue
      //영역이 1이면 그룹생성
      if(Matrix[i][j] == 1){
        d = 1;                   //1의 개수 초기화
        g++;                     //그룹 + 1
        BFS(i, j);               //BFS실행
        group_cnt[g] = d;        //지금 그룹의 1의 개수
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(Matrix[i][j] == 0){
        int cnt = 1;
        //그룹 중복 체크
        int check1 = -1;
        int check2 = -1;
        //주변 4방향 탐색
        for (int k=0;k<4;k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx < 1 || ny < 1 || nx > n || ny > m)continue;
          if (group_member[nx][ny] != 0 && !check[group_member[nx][ny]]){
            cnt += group_cnt[group_member[nx][ny]];
            check[group_member[nx][ny]] = true;
          }
        }
      for (int k=0;k<4;k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx < 1 || ny < 1 || nx > n || ny > m)continue;
          if (group_member[nx][ny] != 0) {
            check[group_member[nx][ny]] = false;
          }
        }
        //max 갱신시켜주기
        if(max_ans < cnt)
          max_ans = cnt;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  input();
  solve();

  cout << max_ans;//답 출력
  return 0;
}