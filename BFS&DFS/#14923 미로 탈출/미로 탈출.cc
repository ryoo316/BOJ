#include<stdio.h>
#include<queue>
typedef struct{
  int x;
  int y;
  int dist;
  int skill;
}coord;

int Matrix[1001][1001] = {};

int visited[1001][1001][2] = {};
//방문체크 (벽 부쉈는지 안 부쉈는지도 방문 체크)
int n,m;

int hx,hy;
int ex,ey;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int x,int y)
{
    std::queue <coord> a;
    a.push({x,y,1,1});
    visited[x][y][0] = 1;

    while(!a.empty()){
        coord now = a.front();
        int dist = now.dist;
        int x = now.x;
        int y = now.y;
        int skill = now.skill;
        a.pop();
        for(int i=0;i<4;i++){
            if(x + dx[i]<=0||y + dy[i]<=0||x + dx[i]>n||y + dy[i]>m)continue;

            if(visited[x + dx[i]][y + dy[i]][skill])continue;

            if(x + dx[i] == ex && y + dy[i] == ey){
                return dist;
            }
            if(Matrix[x + dx[i]][y + dy[i]] == 1){
                if(skill == 1){
                    a.push({x + dx[i],y + dy[i], dist + 1, 0});
                    visited[x + dx[i]][y + dy[i]][0] = 1;
                }
            }
            else if(Matrix[x + dx[i]][y + dy[i]] == 0){
                if(skill == 1){
                    a.push({x + dx[i], y + dy[i], dist + 1, 1});
                    visited[x + dx[i]][y + dy[i]][1] = 1;
                }
                else if(skill == 0){
                    a.push({x + dx[i], y + dy[i], dist + 1, 0});
                    visited[x + dx[i]][y + dy[i]][0] = 1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&hx,&hy,&ex,&ey);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&Matrix[i][j]);
        }
    }
    if(n == 1 && m == 1 && Matrix[1][1] == 0){
      printf("1");
      return 0;
    }
    printf("%d",bfs(hx,hy));
    return 0;
}
