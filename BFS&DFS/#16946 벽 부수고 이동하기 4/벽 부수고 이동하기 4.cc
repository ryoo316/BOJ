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

//기본 맵 배열
char Matrix[Max][Max] = {};      //1000*1000*1 = 1000000
//방문체크 배열
bool visited[Max][Max] = {};     //1000*1000*1 = 1000000

//그룹화하는 배열
int group_member[Max][Max] = {}; //1000*1000*4 = 4000000
int group_cnt[250001] = {};      //250000*4 = 1000000
bool group_check[250001] = {};   //250000*1 = 250000

int ans[Max][Max] = {};      //1000*1000*4 = 4000000

//memory = 11250000Byte = 11.25MB

//행, 열, 그룹멤버
int n, m, gcnt = 0;

int BFS(int s_x, int s_y){
  int cnt = 1;//주변에 이동할 수 있는게 얼마나 있는지 세어주는 변수
  queue<coord> a;
  visited[s_x][s_y] = true;     //지금 위치 방문체크
  a.push({s_x, s_y});           //지금 위치 큐에 넣기
  group_member[s_x][s_y] = gcnt;//지금 시행되는 곳은 그룹 gcnt
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();//큐에서 값 꺼내가
    int x = now.x;
    int y = now.y;
    a.pop();              //큐 pop
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;                     //방문했었다면 continue
      //만약 주변이 이동할 수 있는 지역이면
      if(Matrix[nx][ny] == '0'){  
        a.push({nx, ny});
        visited[nx][ny] = true;                 //방문체크
        group_member[nx][ny] = gcnt;            //gcnt로 그룹화하기
        cnt++;                                  //이동할 수 있으므로 cnt++
      }
    }
  }
  return cnt;//이동할 수 있는 칸의 개수를 반환
}

//입력 받는 함수
void input(){
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
    }
  }
}

//문제를 푸는 함수
void solution(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(visited[i][j])continue;
      if(Matrix[i][j] == '0'){
        gcnt++;
        group_cnt[gcnt] = BFS(i, j);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      //만약 이 칸이 1이라면
      if(Matrix[i][j] == '1'){
        int cnt = 1;//벽을 부쉈으니 1부터
        for(int k=0;k<4;k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면 continue
          if(Matrix[nx][ny] == '1')continue;//벽이라면 continue
          if(group_check[group_member[nx][ny]])continue;   //이미 방문한 그룹이면 continue
          cnt += group_cnt[group_member[nx][ny]];          //그 그룹의 칸의 개수를 더해준다.
          group_check[group_member[nx][ny]] = true;        //그룹 방문체크
        }
        //방문체크해놨던거 다시 풀기
        for(int k=0;k<4;k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면 continue
          if(Matrix[nx][ny] == '1')continue;//벽이라면 continue
          group_check[group_member[nx][ny]] = false;//방문체크 풀기
        }
        ans[i][j] = cnt%10;//답 배열에 얼마나 이동할수 있는지 넣기
      }
    }
  }
}

void solve(){
  input();    //입력
  solution(); //문제풀기
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  //답 출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}