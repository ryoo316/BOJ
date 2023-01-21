#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

//큐 구조체
typedef struct COORD{
  int x;
  int y;
  int dist;
}coord;

//BFS를 사용하기위한 큐
queue<coord> a;

//테케, 너비, 높이, 상근이의 수
int t,w,h,s = 0;

//건물의 상태 배열
char Matrix[MAX][MAX] = {};

//상 하 좌 우 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//BFS 실행 함수
int BFS(){//O(wh)?
  while(!a.empty()){//큐가 빌 때까지 반복한다.
    coord now = a.front();//큐에서 값을 꺼내준다.
    int x = now.x;
    int y = now.y;
    int dist = now.dist;
    a.pop();//다음 큐를 위해 pop해주기
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(Matrix[x][y] == '*'){//지금 불이라면
        if(nx < 1 || ny < 1 || nx > h || ny > w)continue;//범위벗어나면 continue
        if(Matrix[nx][ny] == '.'){//비어있는 곳이면 불이 옮겨붙는다.
          a.push({nx, ny, -1});
          Matrix[nx][ny] = '*';
        }
        else if(Matrix[nx][ny] == '@'){//주변 상근이가 만약 있다면
          Matrix[nx][ny] = '*';//상근이가 불에 탄다.
          s--;//상근이의 수 감소
          if(s == 0)//평행세계의 상근이가 더이상 남아있지 않다면
            return 0;//0 반환
          else
            a.push({nx, ny, -1});//불이 옮겼으므로 큐에 push
        }
      }
      else if(Matrix[x][y] == '@'){//지금 상근이라면
        if(Matrix[nx][ny] == '.'){//비어있다면 상근이가 이동
          a.push({nx, ny, dist + 1});
          Matrix[nx][ny] = '@';
          s++;//상근이의 수 증가
        }
        if(nx < 1 || ny < 1 || nx > h || ny > w){//건물에서 벗어났다면 출력하고 1 반환
          cout << dist + 1 << "\n";
          return 1;
        }
      }
    }
  }
  return 0;
}

int main(){
  cin >> t;//테스트 케이스의 수
  while(t--){//테스트 케이스만큼 반복
    //너비 높이 입력
    cin >> w >> h;
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        //건물의 상태 입력
        cin >> Matrix[i][j];
        if(Matrix[i][j] == '@'){//상근이의 위치를 큐에 넣어준다.
          a.push({i, j, 0});
          s++;//상근이의 수 증가
        }
      }
    }
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        if(Matrix[i][j] == '*')//불의 위치를 큐에 넣어준다.
          a.push({i, j, -1});
      }
    }
    if(!BFS())//0이 반환되었다면 IMPOSSIBLE 출력
      cout << "IMPOSSIBLE" << "\n";
    while(!a.empty()) a.pop();//큐 비워주기
    s = 0;//상근이의 수 초기화
  }
}