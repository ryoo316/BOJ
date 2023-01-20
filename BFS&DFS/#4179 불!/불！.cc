#include<iostream>
#include<queue>
using namespace std;
//행과 열의 MAX값
#define MAX 1001

//큐 구조체
typedef struct COORD{
  int x;        //x 좌표
  int y;        //y 좌표
  int dist;     //거리(시간)
}coord;

//미로의 상태 배열
char Matrix[MAX][MAX] = {};

//행 열
int r,c;

int ji;

//상 하 좌 우 움직이기 위한 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//큐
queue<coord> a;

//BFS 실행 함수
int BFS(){//O(rc)
  while(!a.empty()){                //큐가 빌때까지 반복한다.
    coord now = a.front();          //큐에서 값을 꺼낸다.
    int x = now.x;                  //x값 꺼내기
    int y = now.y;                  //y값 꺼내기
    int dist = now.dist;            //dist값 꺼내기
    a.pop();                        //pop한다.(중요)
    for(int k=0;k<4;k++){
      int nx = x + dx[k];           //하 상
      int ny = y + dy[k];           //우 좌
      if(Matrix[x][y] == 'J'){      //지금 지훈이라면(플레이어)
        if(nx < 1 || ny < 1 || nx > r || ny > c){// 미로에서 벗어나면
          // 탈출 시간 출력
          cout << dist + 1;
          // 리턴
          return 1;  
        }
        else if(Matrix[nx][ny] == '.'){          // 지나갈 수 있는 공간이라면
          // 큐에 넣어주고
          a.push({nx, ny, dist + 1});                            
          // 지훈이가 공간을 이동
          Matrix[nx][ny] = 'J';    
          ji++;
        }
      }
      else if(Matrix[x][y] == 'F'){                      // 지금 불이라면
        if(nx < 1 || ny < 1 || nx > r || ny > c)continue;// 불이 범위를 벗어나면 continue
        if(Matrix[nx][ny] == 'J'){                       // 지훈이가 있다면
          Matrix[nx][ny] = 'F';                          // 지훈이가 불에 탄다...ㅠㅠ
          ji--;                                           // 다른 세카이의 지훈이가 없다면 0을 리턴해준다.
          if(ji == 0)
            return 0;
          else                                           // 다른 세카이의 지훈이가 있다면
            a.push({nx, ny, -1});                        // 큐에 넣어준다 (불에 탔으니)
        }
        else if(Matrix[nx][ny] == '.'){                  // 주변에 불이 이동할 수 있는 공간이면
          // 큐에 넣어준다. (거리는 새지 않으므로 -1)
          a.push({nx, ny, -1});
          // 그 이동할 수 있는 공간에 불이 옮겨진다.
          Matrix[nx][ny] = 'F';
        }
      }
    }
  }
  return 0;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // 행 열 입력
  cin >> r >> c;
  // 미로의 상태를 입력하는 반복문
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      // 미로의 상태 입력
      cin >> Matrix[i][j];
      if(Matrix[i][j] == 'J'){// 지훈이라면  
        a.push({i, j, 0});    // 큐에 넣어준다
        ji++;                  // 지훈이 수 증가
      }
    }
  }
  // 불은 지훈이보다 늦게 움직여야하므로 저 앞 for문에서 넣어주지않는다.
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      if(Matrix[i][j] == 'F'){// 불이라면
        // 큐에 넣어준다 (거리는 새지 않으므로 -1)
        a.push({i, j, -1});
      }
    }
  }
  // 0이 리턴되었다면 지훈이가 미로를 못 빠져나갔거나 불에 탄 상태이므로
  if(!BFS()){
    //IMPOSSIBLE을 출력
    cout << "IMPOSSIBLE";
  }

  // for(int i=1;i<=r;i++){
  //   for(int j=1;j<=c;j++){
  //     cout << Matrix[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
}