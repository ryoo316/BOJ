#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001

//구조체
typedef struct COORD{
  int x;
  int y;
}coord;

//큐
queue<coord> a;

//상 하 좌 우 좌표 움직이기
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//마을의 상태
int Matrix[MAX][MAX] = {};
int ans[4] = {};

//행 열
int n,m;

//BFS 실행 함수
void BFS(){//시간복잡도 O(n^2)?
  while(!a.empty()){        //큐가 빌 때까지 반복
    coord now = a.front();  //큐에서 값을 꺼낸다.
    int x = now.x;
    int y = now.y;
    a.pop();                //pop하기
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m)continue;//범위 벗어나면
      //상 하 좌 우 에 있는 마을 중 감염되지 않은 마을이 있으면
      if(Matrix[nx][ny] == 0){                 
        //1번 바이러스와 2번 바이러스일때만 확장한다.
        if(Matrix[x][y] == 1 || Matrix[x][y] == 2){
          //그 마을이 바이러스에 전염되게 한다.
          Matrix[nx][ny] = Matrix[x][y];
          //큐에 nx, ny를 넣어준다.
          a.push({nx, ny});
        }
      }
      //1번 바이러스와 2번 바이러스가 만났을 때
      else if(Matrix[x][y] == 1 && Matrix[nx][ny] == 2)
      //그 마을의 상태를 3번 바이러스로 전염되게한다.
        Matrix[nx][ny] = 3;
      //2번 바이러스와 1번 바이러스가 만났을 때
      else if(Matrix[x][y] == 2 && Matrix[nx][ny] == 1)
      //그 마을의 상태를 3번 바이러스로 전염되게한다.
        Matrix[nx][ny] = 3;
    }
  }
}

int main(){
  //행 열
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> Matrix[i][j];
    }
  }
  //1번 바이러스와 2번 바이러스를 큐에 넣어준다. (1번 바이러스를 먼저)
  for(int k=1;k<=2;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(k == Matrix[i][j])
          a.push({i, j});
      }
    }
  }
  //BFS를 실행한다.
  BFS();
  //바이러스가 몇개 있는지 세어준다.
  for(int k=1;k<=3;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(k == Matrix[i][j])
          ans[k]++;
      }
    }
  }
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=m;j++){
  //     cout << Matrix[i][j];
  //   }
  //   cout << "\n";
  // }
  //답을 출력한다.
  for(int i=1;i<=3;i++){
    cout << ans[i] << " ";
  }
}