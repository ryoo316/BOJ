#include<stdio.h>

char map[51][51] = {};

int visited[51][51] = {};

int n,m;

int cnt = 0;
int dfs(int x, int y){

    if(visited[x][y] == 1) return 0;

    visited[x][y] = 1;

    if(x < 1 || y < 1 || x > n || y > m) return 0;

    if(map[x][y] == '-'){
        if(map[x][y+1] == '-' && visited[x][y+1] == 0){
            dfs(x, y+1);
        }
        if(map[x][y-1] == '-' && visited[x][y-1] == 0){
            dfs(x, y-1);
        }
    }
    if(map[x][y] == '|'){
        if(map[x+1][y] == '|' && visited[x+1][y] == 0){
            dfs(x+1, y);
        }
        if(map[x-1][y] == '|' && visited[x-1][y] == 0){
            dfs(x-1, y);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j] == '-' && visited[i][j] == 0){
                dfs(i,j);
                cnt++;
            }
            if(map[i][j] == '|' && visited[i][j] == 0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}
