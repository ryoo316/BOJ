#include<stdio.h>
//기본 맵 배열
int map[101][101] = {0,};
//방문 체크 배열
int visited[101][101] = {0,};
//상 하 좌 우 탐색 배열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//영역의 개수
int areacnt = 0;
//각 영역의 넓이
int area[101] = {0,};
int m,n;
//dfs 탐색 함수
int dfs(int x,int y)
{
    //방문 체크
    visited[x][y] = 1;

    if(x<=-1||y<=-1||x>=m||y>=n) return -1;

    area[areacnt]++;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<=-1||ny<=-1||nx>=m||ny>=n)continue;
        if(visited[nx][ny])continue;

        if(map[nx][ny] == 0){
            dfs(nx,ny);
        }
    }
}
int main()
{
    int k;
    scanf("%d%d%d",&m,&n,&k);

    for(int e=1;e<=k;e++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=y1;i<y2;i++){
            for(int j=x1;j<x2;j++){
                map[i][j] = 1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j])continue;
            if(map[i][j] == 0){
                areacnt++;
                dfs(i,j);
            }
        }
    }
    for(int i=1;i<=areacnt;i++){
        for(int j=1;j<=areacnt;j++){
            if(area[i]<area[j]){
                int temp = area[i];
                area[i] = area[j];
                area[j] = temp;
            }
        }
    }


    printf("%d\n",areacnt);
    for(int i=1;i<=areacnt;i++){
        printf("%d ",area[i]);
    }
}

