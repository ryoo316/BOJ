#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

//큐 구조체
typedef struct COORD{
  int x;              // x 좌표
  int y;              // y 좌표
  int dist;           // 거리(시간)
}coord;

//BFS를 사용하기 위한 큐
queue<coord> a;

//지도의 상태 배열
char Matrix[MAX][MAX] = {};

//상 하 좌 우 탐색 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//행 열 고슴도치 수(평행세계의 고슴도치)
int r,c,s = 0;

int BFS(){
  //큐가 빌 때까지 반복
  while(!a.empty()){
    coord now = a.front();//큐에서 값 꺼내기
    int x = now.x;
    int y = now.y;
    int dist = now.dist;
    a.pop();              //다음 큐 원소를 꺼내기 위해 pop을 해준다
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > r || ny > c)continue;//범위 벗어나면
      if(Matrix[x][y] == '*'){                         //지금 물일때
        if(Matrix[nx][ny] == '.'){                     //주변이 비어있으면
          a.push({nx, ny, -1});                        
          Matrix[nx][ny] = '*';                        //물로 채운다
        }
        else if(Matrix[nx][ny] == 'S'){                //주변에 고슴도치가 있으면
          Matrix[nx][ny] = '*';                        //물로 차있게하고
          s--;                                         //평행세계의 고슴도치 줄이기
          if(s == 0)                                   //남아있는 다른 세계의 고슴도치가 없다면
            return 0;                                  //0 반환
          else
            a.push({nx, ny, -1});                      //아니면 큐에 넣어주기
        }
      }
      else if(Matrix[x][y] == 'S'){                    //지금 고슴도치일때
        if(Matrix[nx][ny] == 'D'){                     //출구 이면
          cout << dist + 1;                            //시간을 출력하고 1을 반환한다.
          return 1;
        }
        else if(Matrix[nx][ny] == '.'){                //주변이 비어있으면
          a.push({nx, ny, dist + 1});
          Matrix[nx][ny] = 'S';                        //이동한다.
          s++;                                         //평행세계의 고슴도치++
        }
      }
    }
  }
  return 0;
}

int main(){
  //행 열 입력받기
  cin >> r >> c;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      //지도의 상태를 입력받는다
      cin >> Matrix[i][j];
      if(Matrix[i][j] == 'S'){//고슴도치가 있다면 큐에 넣어준다.
        a.push({i, j, 0});
        s++;
      } 
    }
  }
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      if(Matrix[i][j] == '*')//물이 있다면 큐에 넣어준다.
        a.push({i, j, -1});
    }
  }
  //BFS 실행
  if(!BFS())//만약 0이 반환되었다면 고슴도치가 도착을 못했다는 뜻이니
    cout << "KAKTUS";//KAKTUS 출력
  // cout << "\n";
  // for(int i=1;i<=r;i++){
  //   for(int j=1;j<=c;j++){
  //     cout << Matrix[i][j];
  //   }
  //   cout << "\n";
  // }
}