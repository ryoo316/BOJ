#include<stdio.h>

int map[251][251] = {};

int visited[251][251] = {};

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,-1,1,1,-1};

int n,m,cnt = 0;

int dfs(int x, int y){
    visited[x][y] = 1;

    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny] == 1)continue;

        if(nx >= 1 && ny >= 1 && nx <= n && ny <= m){
            if(map[nx][ny] == 1){
                dfs(nx,ny);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j])continue;
            if(map[i][j] == 1){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}
