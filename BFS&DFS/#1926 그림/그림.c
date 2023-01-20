#include<stdio.h>

int map[501][501] = {};

int visited[501][501] = {};

int n,m,cnt = 0;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int paint[250000] = {};

int dfs(int x, int y){
    if(visited[x][y] == 1) return 0;

    visited[x][y] = 1;

    paint[cnt]++;

    for(int i=0;i<4;i++){
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

    int max = -99999;
    for(int i=0;i<=cnt;i++){
        if(max < paint[i]) max = paint[i];
    }

    printf("%d\n%d",cnt,max);
    return 0;
}
