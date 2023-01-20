#include<stdio.h>
#include<queue>


// 좌표
typedef struct COORD{
  int x;
  int y;
  int z;
  int dist;
}coord;

// 동 서 남 북 상 하
int dx[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};

int main(){
  while(1){
    int l,r,c;
    // 층, 행, 열
    scanf("%d %d %d", &l, &r, &c);
    if(l == 0 && r == 0 && c == 0)
      break;
    std::queue<coord> q;
    // 행렬로 표현되는 맵 선언
    char Matrix[31][31][31] = {};
    // 방문 체크 배열
    int visited[31][31][31] = {};
     
    for(int k=1;k<=l;k++){//층
      for(int i=1;i<=r;i++){//행
        for(int j=1;j<=c;j++){//열
          scanf(" %c",&Matrix[i][j][k]);
          if(Matrix[i][j][k] == 'S'){
            q.push({i,j,k,0});
            visited[i][j][k] = 1;
          }
        }
      }
    }
    int flag = 1;
    while(!q.empty()){
      coord now = q.front();
      int x = now.x;
      int y = now.y;
      int z = now.z;
      int dist = now.dist;
      q.pop();
      for(int i=0;i<6;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        if(nx < 1 || ny < 1 || nz < 1)continue;
        if(nx > r || ny > c || nz > l)continue;
        if(visited[nx][ny][nz])continue;
        
        if(Matrix[nx][ny][nz] == 'E' && flag == 1){
          printf("Escaped in %d minute(s).\n",dist + 1);
          flag = 0;
          break;
        }
        if(Matrix[nx][ny][nz] == '.'){
          q.push({nx, ny, nz, dist + 1});
          visited[nx][ny][nz] = 1;
        }
      }
    }
    if(flag)
      printf("Trapped!\n");
  }
  return 0;
}