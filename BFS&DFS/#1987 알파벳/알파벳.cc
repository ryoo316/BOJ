#include<iostream>
#include<queue>
#define Max 21
using namespace std;

typedef pair<int, int> v;

int r, c, mx = 0;
char Matrix[Max][Max] = {};
bool visited[Max][Max] = {};
bool alp[27] = {};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void DFS(int x, int y, int cnt){
    mx = max(mx, cnt);
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > r || ny > c)continue;
        if(visited[nx][ny])continue;
        if(alp[Matrix[nx][ny] - '0'])continue;
        visited[nx][ny] = true;
        alp[Matrix[nx][ny] - '0'] = true;
        DFS(nx, ny, cnt + 1);
        visited[nx][ny] = false;
        alp[Matrix[nx][ny] - '0'] = false;
    }
}

void Input(){
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> Matrix[i][j];
        }
    }
}

void Solution(){
    visited[1][1] = true;
    alp[Matrix[1][1] - '0'] = true;
    DFS(1, 1, 1);
    cout << mx;
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