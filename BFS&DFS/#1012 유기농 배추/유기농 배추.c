#include<stdio.h>
int map[51][51] = {};

int visited[51][51] = {};

int n,m,k,test;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt = 0;
int dfs(int x,int y)
{
    visited[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny])continue;
        if(nx>=0&&ny>=0&&nx<=n&&ny<=m){
            if(map[nx][ny] == 1){
                dfs(nx,ny);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&test);
    for(int t=0;t<test;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] == 1 && visited[i][j] == 0){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        cnt = 0;
    }

    return 0;
}
