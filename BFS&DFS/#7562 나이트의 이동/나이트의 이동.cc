#include<stdio.h>
#include<queue>

typedef struct{
    int x;
    int y;
    int dist;
}coord;



int dx[8] = {1, -1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, -1, 1, -2, -2, -1, 1};

int m;
int bfs(int x1,int y1,int x2,int y2)
{
    std::queue <coord> a;
    if(x1 == x2 && y1 == y2)
        return 0;
    int visited[301][301] = {};
    a.push({x1, y1, 0});
    visited[x1][y1] = 1;

    while(!a.empty()){
        coord now = a.front();
        int x = now.x;
        int y = now.y;
        int dist = now.dist;
        //printf("%d %d %d\n", x, y, dist);
        a.pop();

        for(int i=0;i<8;i++){
            if(x+dx[i] >= 0 && y+dy[i] >= 0 && x+dx[i] < m && y+dy[i] < m &&
               visited[x+dx[i]][y+dy[i]] == 0){
                if(x+dx[i] == x2 && y+dy[i] == y2){
                    return dist+1;
                }
                a.push({x+dx[i], y+dy[i], dist+1});
                visited[x+dx[i]][y+dy[i]]=1;
            }

        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n", bfs(x1,y1,x2,y2));
    }
    return 0;
}
