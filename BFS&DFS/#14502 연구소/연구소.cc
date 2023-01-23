#include<iostream>
#include<queue>
#include<cstring>
#define MAX 9
using namespace std;

//큐 구조체
typedef struct COORD{
  int x;
  int y;
}coord;

//맵의 상태 배열
int Matrix[MAX][MAX] = {};

//방문 체크 배열
int visited[MAX][MAX] = {};

//상 하 좌 우 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//행, 열, 안전 영역, 벽, 최대 안전 영역
int n, m, safe_area = 0, w = 0, max_area = 0;

void BFS(){
  queue<coord> a;
  int CMatrix[MAX][MAX] = {};//원래 맵을 훼손하지않기위해 맵을 copy해준다.
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      CMatrix[i][j] = Matrix[i][j];
      //바이러스가 있으면 그 위치를 큐에 넣어준다.
      if(CMatrix[i][j] == 2){
        a.push({i, j});
        visited[i][j] = 1;
      }
    }
  }
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();//큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();//다음 큐값을 꺼내기 위해 pop해준다.
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue; //범위 벗어나면 continue
      if(visited[nx][ny])continue;                      //이미 방문된 위치이면 continue
      if(CMatrix[nx][ny] == 0){     //바이러스가 확산될 수 있는 칸이라면
        CMatrix[nx][ny] = 2;        //바이러스가 그 칸에 확산
        a.push({nx, ny});           //큐에 넣기
        visited[nx][ny] = 1;        //방문
      }
    }
  }
  //안전 영역의 수 구하기
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(CMatrix[i][j] == 0){
        safe_area++;
      }
    }
  }
  //최대 안전 영역 갱신
  if(max_area < safe_area)
    max_area = safe_area;
  safe_area = 0;//안전 영역 초기화
  memset(visited, 0, sizeof(visited));//방문체크 배열 초기화
}

//백트래킹방식을 사용해 벽을 다 세워본다.
void walls(int w){
  //만약 벽이 다 세워졌으면 BFS를 실행한다.
  if(w == 3){
    BFS();
    return;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(Matrix[i][j] == 0){
        Matrix[i][j] = 1;//벽을 세우고
        walls(w + 1);
        Matrix[i][j] = 0;//다음을 위해 벽을 없앤다.
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //행 열 입력
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
    }
  }
  //벽 세우고 BFS
  walls(0);
  //최대 안전 영역 출력하기
  cout << max_area;
}
