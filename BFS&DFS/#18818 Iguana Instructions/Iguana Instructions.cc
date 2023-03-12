#include<iostream>
#include<queue>
#include<algorithm>
constexpr auto Max = 101;
constexpr auto INF = 1e9 + 7;
using namespace std;

typedef pair<int, pair<int, int>> v;

int n;
int D[Max][Max][4] = {};
bool visited[Max][Max][4] = {};

char Matrix[Max][Max] = {};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void BFS(){
    queue<v> Q;
    for(int i=0;i<4;i++){
        D[1][1][i] = 0;
        visited[1][1][i] = true;
    }
    Q.push({-1, {1, 1}});
    while(!Q.empty()){
        int dir = Q.front().first;
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        Q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
            if(Matrix[nx][ny] == '#')continue;
            if(dir == i){
                if(visited[nx][ny][i]){
                    if(D[nx][ny][i] <= D[x][y][dir])
                        continue;
                }
                else{
                    visited[nx][ny][i] = true;
                }
                D[nx][ny][i] = D[x][y][dir];
            }
            else{
                if(visited[nx][ny][i]){
                    if(D[nx][ny][i] <= D[x][y][dir] + 1)
                        continue;
                }
                else{
                    visited[nx][ny][i] = true;
                }
                D[nx][ny][i] = D[x][y][dir] + 1;
            }
            Q.push({i, {nx, ny}});
        }
    }
}

void Input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Matrix[i][j];
        }
    }
}

void Solution(){
    BFS();
    int mn = INF;
    for(int i=0;i<4;i++){
        if(!visited[n][n][i])continue;
        mn = min(mn, D[n][n][i]);
    }
    cout << mn;
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