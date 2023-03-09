#include<iostream>
#include<queue>
#include<utility>
#define Max 101
using namespace std;

typedef pair<int, pair<int, int>> v;

//상 우 하 좌 탐색 배열
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//미로 맵 배열
char Matrix[Max][Max] = {};
bool visited[Max][Max] = {};

//행, 열, 벽을 최소 몇 개 부수는지
int h, w, min_b_cnt = INT32_MAX;

//BFS실행 함수
void BFS(){
  //우선순위 큐
  priority_queue<v, vector<v>, greater<v>> pq;
  pq.push({0, {1, 1}});
  visited[1][1] = true;
  //큐가 빌 때까지 반복한다.
  while(!pq.empty()){
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    int b_cnt = -pq.top().first;
    pq.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;  //범위 벗어나면 continue
      if(visited[nx][ny])continue;
      if(nx == h && ny == w){
        min_b_cnt = -b_cnt;
      }
      if(Matrix[nx][ny] == '1')
        pq.push({-b_cnt + 1, {nx, ny}});
      else if(Matrix[nx][ny] == '0')
        pq.push({-b_cnt, {nx, ny}});
      visited[nx][ny] = true;
    }
  }
}

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> w >> h;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
    }
  }
}

int main(){
  input();
  
  BFS();
  if(w == 1 && h == 1)
    cout << 0;
  else
    cout << min_b_cnt;//답 출력
  return 0;
}