#include<stdio.h>

int map[101][101] = {0,};

int visited[101][101][101] = {0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt[101] ={0,};

int n;

int high = -1,areacnt = 0;

int dfs(int x,int y)
{
    visited[x][y][high] = 1;

    if(x<=0||y<=0||x>=n+1||y>=n+1) return -1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<=0||ny<=0||nx>=n+1||ny>=n+1)continue;
        if(visited[nx][ny][high])continue;

        if(map[nx][ny] > high){
            dfs(nx,ny);
        }
    }
}
int main()
{
    int max = -99999;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int h=0;h<=100;h++){
        high++;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(visited[i][j][high])continue;
                if(map[i][j] > high){
                    dfs(i,j);
                    cnt[h]++;
                }
            }
        }
        if(cnt[h] > max) max = cnt[h];
    }
    printf("%d",max);
    return 0;
}

