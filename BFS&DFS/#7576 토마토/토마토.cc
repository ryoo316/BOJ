#include<stdio.h>
#include<queue>

typedef struct{
    int x;
    int y;
    int dist;
}coord;
int tomato[1001][1001] = {};

int visited[1001][1001] = {};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
std::queue <coord> a;
int n,m;
int bfs(int x1,int y1)
{

    visited[x1][y1] = 1;

    while(!a.empty()){//큐가 빌때까지 반복하기
      coord now = a.front();
      int x = now.x;
      int y = now.y;
      int dist = now.dist;
      a.pop();
      for(int i=0;i<4;i++){
        if(x+dx[i]>=1&&y+dy[i]>=1&&x+dx[i]<=n&&y+dy[i]<=m){
          if(!tomato[x+dx[i]][y+dy[i]] && !visited[x+dx[i]][y+dy[i]]){
            tomato[x+dx[i]][y+dy[i]] = tomato[x][y] + 1;
            visited[x+dx[i]][y+dy[i]] = 1;
            a.push({x+dx[i],y+dy[i],dist+1});
          }
        }
      }
    }
    return -1;
}
int main()
{
    int g=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        scanf("%d",&tomato[i][j]);
        if(tomato[i][j] == 1){
            a.push({i,j,1});//1이면 시작값 넣어주기
        }
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(tomato[i][j] == 1){
          g++;
        }
      }
    }
    if(g == m*n){//다 익은 상태면 0 출력
      printf("0");
      return 0;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(tomato[i][j] == 1){//익은 곳 있으면 거기서 bfs돌기
          bfs(i,j);
        }
      }
    }
    /*bfs 돌았는데 익지 않은 곳이 있다면 모두 익지 못하는 상황 따라서 -1 출력 후 끝냄*/
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(tomato[i][j] == 0){
          printf("-1");
          return 0;
        }
      }
    }
    int max = 0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(tomato[i][j] > max){
          max = tomato[i][j];
        }
      }
    }
    /*
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        printf("%3d ",tomato[i][j]);
      }
      printf("\n");
    }*/
    printf("%d",max-1);
    return 0;
}
