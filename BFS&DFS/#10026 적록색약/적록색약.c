#include<stdio.h>

char map[101][101] = {};

int visited[101][101] = {};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n;

int cnt1 = 0,cnt2 = 0;
int dfs_1(int x,int y)
{
    visited[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny])continue;

        if(nx >= 1 && ny >= 1 && nx <= n && ny <= n){
            if(map[x][y] == map[nx][ny]){
                dfs_1(nx,ny);
            }
        }
    }
}
int dfs_2(int x,int y)
{
    visited[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny])continue;

        if(nx >= 1 && ny >= 1 && nx <= n && ny <= n){
            if(map[x][y] == map[nx][ny]){
                dfs_2(nx,ny);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&map[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j])continue;
            if(map[i][j] == 'R' || map[i][j] == 'B' || map[i][j] == 'G'){
                dfs_1(i,j);
                cnt1++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j] = 0;
            if(map[i][j] == 'G')
                map[i][j] = 'R';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j])continue;
            if(map[i][j] == 'R' || map[i][j] == 'B'){
                dfs_2(i,j);
                cnt2++;
            }
        }
    }
    printf("%d %d",cnt1,cnt2);
}
