#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

//큐 구조체
struct coord{
  int x;
  int y;
};

//상 하 좌 우
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//크기, 몇 개일때 터지는지
int n, k;

//맵 상태 배열
char Matrix[101][11] = {};
//방문체크 배열
int visited[101][11] = {};

//폭발되었는지 확인하는 변수
int is_explosion = 0;

//터지는걸 구현한 함수
void Explosion(int s_x, int s_y){
  queue<coord> a;
  visited[s_x][s_y] = 0;     //방문체크
  a.push({s_x, s_y});        //큐에다 값 넣기
  char c = Matrix[s_x][s_y]; //터질 블럭 저장
  Matrix[s_x][s_y] = '0';
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > 10)continue;//범위벗어나면 continue
      if(!visited[nx][ny])continue;//방문되었으면 continue
      if(Matrix[nx][ny] != c)continue;//터질 블럭하고 다르면 continue
      
      a.push({nx, ny});      //큐에다 다음 값 넣기
      visited[nx][ny] = 0;   //방문체크
      Matrix[nx][ny] = '0';  //터짐
    }
  }
}

//BFS 실행 함수
void BFS(int s_x, int s_y){
  int cnt = 1;//같은 블럭이 몇개인지 세주는 변수
  queue<coord> a;
  visited[s_x][s_y] = 1;   //방문체크
  a.push({s_x, s_y});      //큐에 지금 위치를 넣어준다.
  //큐가 빌 때까지 반복한다.
  while(!a.empty()){
    coord now = a.front(); //큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > 10)continue;//범위 벗어나면 continue
      if(visited[nx][ny])continue;//이미 방문되었으면 continue
      if(Matrix[nx][ny] != Matrix[x][y])continue;//다른 블럭이면 continue
      
      visited[nx][ny] = 1;  //방문체크
      a.push({nx, ny});     //큐에 넣기
      cnt++;                //블럭 + 1
    }
  }
  //같은 블럭이 k 이상이면 폭발.
  if(cnt >= k){
    Explosion(s_x, s_y);
    is_explosion = 1;//폭발되었음을 표시
  }
}

//블럭들을 아래로 내려보내는 함수
void move_down(){
  int j = 1;//1열부터 확인한다.
  while(1){
    //아래부터 확인한다.
    for(int i=n;i>=1;i--){
      if(Matrix[i][j] != '0')continue;//블럭이면 continue
      for(int k=i;k>=1;k--){
        if(Matrix[k][j] != '0'){//블럭과 빈 곳을 swap한다.
          char c = Matrix[k][j];
          Matrix[k][j] = Matrix[i][j];
          Matrix[i][j] = c;
          break;//바뀌었으므로 break
        }
      }
    }
    j++;//다음 열을 확인하기 위해 열 + 1
    if(j == 11)//열이 범위를 벗어나면 break해서 반복문에서 벗어난다.
      break;
  }
}

//입력받는 함수
void input(){
  //입력
  cin >> n >> k;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=10;j++)
      cin >> Matrix[i][j];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  input();//입력받기
  
  while(1){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=10;j++){
        if(visited[i][j])continue;//방문되었으면 continue
        if(1 <= Matrix[i][j] - '0' && Matrix[i][j] - '0' <= 9)//1 ~ 9사이
          BFS(i, j);
      }
    }
    //폭발하지않았다면 break
    if(!is_explosion)
      break;
    //아니면 블럭을 내려준다.
    else
      move_down();

    //방문체크와 폭발확인변수를 초기화시켜준다.
    is_explosion = 0;
    memset(visited, 0, sizeof(visited));
  }

  //답 출력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=10;j++){
      cout << Matrix[i][j];
    }
    cout << "\n";
  }
  
  return 0;
}