#include<stdio.h>
#include<queue>

typedef struct{
    int x;
    int y;
    int z;
    int dist;
}coord;
std::queue <coord> a;
int tomato[101][101][101] = {};

int visited[101][101][101] = {};

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int m,n,h;


void bfs(int x1,int y1,int z1)
{

    visited[x1][y1][z1] = 1;

    while(!a.empty()){
        coord now = a.front();
        int x = now.x;
        int y = now.y;
        int z = now.z;
        int dist = now.dist;
        a.pop();
        for(int i=0;i<6;i++){
            if(visited[x+dx[i]][y+dy[i]][z+dz[i]])continue;

            if(x+dx[i] >= 1 && x+dx[i] <= n){
                if(y+dy[i] >= 1 && y+dy[i] <= m){
                    if(z+dz[i] >=1 && z+dz[i] <= h){
                        if(tomato[x+dx[i]][y+dy[i]][z+dz[i]]==0){
                            visited[x+dx[i]][y+dy[i]][z+dz[i]] = 1;
                            tomato[x+dx[i]][y+dy[i]][z+dz[i]] = tomato[x][y][z] + 1;
                            a.push({x+dx[i],y+dy[i],z+dz[i],dist+1});
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int t1 = 0,t2 = 0;
    scanf("%d%d%d",&m,&n,&h);
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&tomato[i][j][k]);
                if(tomato[i][j][k] == 1)
                    a.push({i,j,k,1});//1이면 시작값 넣어주기
                else if(tomato[i][j][k] == -1)
                    t2++;
            }
        }
    }
    if(t2 == h*n*m){//전 구간에 토마토가 없으면 -1 출력 후 끝내기
        printf("-1");
        return 0;
    }
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(tomato[i][j][k] == 1 || tomato[i][j][k] == -1){
                    t1++;
                }
            }
        }
    }
    if(t1 == h*n*m){//이미 다 익어있으면 0 출력 후 끝내기
        printf("0");
        return 0;
    }

    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(visited[i][j][k])continue;
                if(tomato[i][j][k] == 1){//익어있으면 거기서 bfs돌기
                    bfs(i,j,k);
                }
            }
        }
    }
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(tomato[i][j][k] == 0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    /*for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",tomato[i][j][k]);
            }
            printf("\n");
        }
    }*/
    int max = 0;
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(max < tomato[i][j][k])
                    max = tomato[i][j][k];
            }
        }
    }
    printf("%d",max-1);
    return 0;
}
/*
-----(O)
3 3 2
1 1 0
1 1 0
0 0 0
0 0 0
0 1 1
0 1 1
ans  = 1
-----(O)
2 2 1
-1 -1
-1 -1
ans = -1
-----(O)
5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
ans = 7
*/
