#include<stdio.h>
//기본 맵 구조 배열
int map[26][26] = {0,};
//변수들
int n,complexcnt = 0;
//방문 체크 배열
int visited[26][26] = {0,};
//상 하 좌 우 탐색 배열
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
//단지 내 집의 수
int house[300] = {0,};
//dfs 탐색 함수
int dfs(int x,int y)
{
    //범위 밖이면 나가기
    if(x==0||x==n+1||y==0||y==n+1) return 0;
    //방문 체크
    visited[x][y] = 1;
    //단지내 집의 수 증가
    house[complexcnt]++;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny])continue;
        if(nx>1||ny>1||nx<=n||ny<=n){
            if(map[nx][ny] == 1){
                dfs(nx,ny);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                dfs(i,j);
                complexcnt++;
            }
        }
    }
    /*단지내 집의 수 오름차순으로 정렬*/
    for(int i=0;i<=complexcnt;i++){
        for(int j=0;j<=complexcnt;j++){
        if(house[i]<house[j]){
            int temp = house[i];
            house[i] = house[j];
            house[j] = temp;
            }
        }
    }

    /*단지수와 단지내 집의 수 출력*/
    printf("%d\n",complexcnt);
    for(int i=1;i<=complexcnt;i++){
        printf("%d\n",house[i]);
    }
    return 0;
}
