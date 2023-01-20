#include<stdio.h>
#include<queue>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int net[101][101] = {0},visited[101] = {0};
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);

        net[a][b] = 1;
        net[b][a] = 1;
    }
    std::queue <int> a;
    a.push(1);
    visited[1] = 1;
    int infected = 0;
    while(!a.empty()){
        int now = a.front();
        a.pop();
        for(int i=1;i<=n;i++){
            if(net[now][i] == 1 && !visited[i]){
                visited[i] = 1;
                a.push(i);
                infected++;
            }
        }
    }
    printf("%d",infected);
    return 0;
}
