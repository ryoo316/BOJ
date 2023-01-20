#include<stdio.h>
#include<queue>
typedef struct{
  int x;
  int y;
  int dist;
  int cnt;
}coord;

int Matrix[1005][1005] = {};

int visited[1005][1005][11] = {};
//방문체크 (벽 부쉈는지 안 부쉈는지도 방문 체크)
int n,m,k;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x,int y)
{
    std::queue <coord> a;
    a.push({x,y,1,0});
    visited[x][y][0] = 1;

    while(!a.empty()){
        coord now = a.front();
        int dist = now.dist;
        int x = now.x;
        int y = now.y;
        int cnt = now.cnt;
        a.pop();
        for(int i=0;i<4;i++){
            if(x + dx[i]<=0||y + dy[i]<=0||x + dx[i]>n||y + dy[i]>m)continue;
            if(visited[x + dx[i]][y + dy[i]][cnt])continue;

            if(x + dx[i] == n && y + dy[i] == m){
                return dist+1;
            }
            if(Matrix[x + dx[i]][y + dy[i]] == 1){
                if(cnt < k && visited[x + dx[i]][y + dy[i]][cnt - 1] == 0){
                    a.push({x + dx[i],y + dy[i], dist + 1, cnt + 1});
                    visited[x + dx[i]][y + dy[i]][cnt + 1] = 1;
                }
            }
            else if(Matrix[x + dx[i]][y + dy[i]] == 0){
                a.push({x + dx[i], y + dy[i], dist + 1, cnt});
                visited[x + dx[i]][y + dy[i]][cnt] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&Matrix[i][j]);
        }
    }
    if(n == 1 && m == 1 && Matrix[1][1] == 0){
      printf("1");
      return 0;
    }
    printf("%d",bfs(1,1));
    return 0;
}
