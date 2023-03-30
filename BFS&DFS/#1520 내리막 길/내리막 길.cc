#include<iostream>
#include<cstring>
#define Max 501
using namespace std;

int h, w;
int Matrix[Max][Max];
int visited[Max][Max];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void Input(){
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> Matrix[i][j];
        }
    }
}

int DFS(int x, int y){
    if(x == h && y == w) return 1;
    if(visited[x][y] != -1) return visited[x][y];
    visited[x][y] = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
        if(Matrix[x][y] <= Matrix[nx][ny])continue;
        visited[x][y] += DFS(nx, ny);
        // for(int i=1;i<=h;i++){
        //     for(int j=1;j<=w;j++){
        //         if(visited[i][j] == -1)
        //             cout << "x ";
        //         else
        //             cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    return visited[x][y];
}

void Solution(){
    memset(visited, -1, sizeof(visited));
    DFS(1, 1);
    cout << visited[1][1];
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}