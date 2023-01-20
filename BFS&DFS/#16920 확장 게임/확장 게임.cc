#include<stdio.h>
#include<queue>
using namespace std;
#define MAX 1001

typedef struct COORD{
  int x;      //x 좌표
  int y;      //y 좌표
}coord;

queue<coord> a[10];

char Matrix[MAX][MAX] = {};
int castle[10] = {};
int ans[10] = {};

//상 하 좌 우
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n,m,p;

//BFS함수
void BFS(){
  while(1){
    for(int k=1;k<=p;k++){
      int move = castle[k];
      while(!a[k].empty() && move--){
        int size = a[k].size();
        for(int t=0;t<size;t++){
          //큐를 꺼내준다.
          coord now = a[k].front();
          int x = now.x;
          int y = now.y;
          //큐 pop한다.
          a[k].pop();
          for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //범위 벗어나면 continue
            if(nx < 1 || ny < 1 || nx > n || ny > m)continue;
            //만약 다음 칸이 '.'이라면
            if(Matrix[nx][ny] == '.'){
              //다음 칸을 플레이어의 수로 바꾸기
              Matrix[nx][ny] = Matrix[x][y];
              //큐에 넣어주기
              a[k].push({nx, ny});
              //성의 수
              ans[k]++;
            }
          }
        }
      }
    }
    int flag = 1;
    for(int i=1;i<=p;i++){
      while(!a[i].empty()){//아직 큐가 비어있지 않다면 계속 반복하기
        flag = 0;
        break;
      }
    }
    if(flag) break;
  }
}

int main(){
  //행 열 플레이어의 수 입력
  scanf("%d%d%d",&n,&m,&p);
  //플레이어가 한번에 확장할 수 있는 수
  for(int i=1;i<=p;i++){
    scanf("%d",&castle[i]);
  }
  //게임판의 상태를 입력
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf(" %c",&Matrix[i][j]);
    }
  }
  //1번 플레이어부터 push
  for(int k=1;k<=p;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        //만약 성이 있다면 큐에 push해준다.
        if(k == Matrix[i][j] - 48){
          a[k].push({i, j});
          ans[k]++;
        }
      }
    }
  }
  //BFS 실행
  BFS();
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=m;j++){
  //     printf("%c ",Matrix[i][j]);
  //   }
  //   printf("\n");
  // }
  //답 출력
  for(int i=1;i<=p;i++){
    printf("%d ",ans[i]);
  }
  return 0;
}