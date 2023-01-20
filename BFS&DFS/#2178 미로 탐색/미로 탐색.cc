#include<stdio.h>
#include<queue>
typedef struct{
    int x;
    int y;
    int dist;
}coord;

int test[101][101] = {};

int visited[101][101] = {};

int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x,int y)
{
    std::queue <coord> a;
    a.push({x,y,1});
    visited[x][y] = 1;

    while(!a.empty()){
        coord now = a.front();
        int dist = now.dist;
        int x = now.x;
        int y = now.y;
        a.pop();

        for(int i=0;i<4;i++){
            if(x + dx[i]<=0||y + dy[i]<=0||x + dx[i]>n||y + dy[i]>m)continue;
            if(visited[x + dx[i]][y + dy[i]])continue;

            if(x + dx[i] == n && y + dy[i] == m){
                return dist+1;
            }
            if(test[x + dx[i]][y + dy[i]] == 1){
            a.push({x + dx[i],y + dy[i],dist+1});
            visited[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&test[i][j]);
        }
    }
    printf("%d",dfs(1,1));
    return 0;
}
