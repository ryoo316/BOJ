#include<iostream>
#include<queue>
constexpr auto Max = 101;
constexpr auto INF = 1e9 + 7;
using namespace std;

typedef pair<int, pair<int, int>> v;

int n, m, sx, sy, sdir, ex, ey, edir;
int D[Max][Max][5] = {};

bool visited[Max][Max][5] = {};
char Matrix[Max][Max] = {};

int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};

void BFS(){
    queue<v> Q;
    visited[sx][sy][sdir] = true;
    Q.push({sdir, {sx, sy}});
    while(!Q.empty()){
        int dir = Q.front().first;
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        Q.pop();
        if(dir == 1){//동쪽
            //북
            int ndir = 4;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //남
            ndir = 3;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //동
            int nx = x;
            int ny = y;
            for(int i=1;i<=3;i++){
                ny++;
                if(ny > m)break;
                if(Matrix[nx][ny] == '1')break;
                if(visited[nx][ny][dir]){
                    if(D[nx][ny][dir] > D[x][y][dir] + 1){
                        D[nx][ny][dir] = D[x][y][dir] + 1;
                        Q.push({dir, {nx, ny}});
                    }
                }
                else{
                    visited[nx][ny][dir] = true;
                    D[nx][ny][dir] = D[x][y][dir] + 1;
                    Q.push({dir, {nx, ny}});
                }
            }
        }
        else if(dir == 2){//서쪽
            //북
            int ndir = 4;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //남
            ndir = 3;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //서
            int nx = x;
            int ny = y;
            for(int i=1;i<=3;i++){
                ny--;
                if(ny < 1)break;
                if(Matrix[nx][ny] == '1')break;
                if(visited[nx][ny][dir]){
                    if(D[nx][ny][dir] > D[x][y][dir] + 1){
                        D[nx][ny][dir] = D[x][y][dir] + 1;
                        Q.push({dir, {nx, ny}});
                    }
                }
                else{
                    visited[nx][ny][dir] = true;
                    D[nx][ny][dir] = D[x][y][dir] + 1;
                    Q.push({dir, {nx, ny}});
                }
            }
        }
        else if(dir == 3){//남쪽
            //서
            int ndir = 2;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //동
            ndir = 1;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //남
            int nx = x;
            int ny = y;
            for(int i=1;i<=3;i++){
                nx++;
                if(nx > n)break;
                if(Matrix[nx][ny] == '1')break;
                if(visited[nx][ny][dir]){
                    if(D[nx][ny][dir] > D[x][y][dir] + 1){
                        D[nx][ny][dir] = D[x][y][dir] + 1;
                        Q.push({dir, {nx, ny}});
                    }
                }
                else{
                    visited[nx][ny][dir] = true;
                    D[nx][ny][dir] = D[x][y][dir] + 1;
                    Q.push({dir, {nx, ny}});
                }
            }
        }
        else{//북쪽
            //서
            int ndir = 2;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //동
            ndir = 1;
            if(visited[x][y][ndir]){
                if(D[x][y][ndir] > D[x][y][dir] + 1){
                    D[x][y][ndir] = D[x][y][dir] + 1;
                    Q.push({ndir, {x, y}});
                }
            }
            else{
                visited[x][y][ndir] = true;
                D[x][y][ndir] = D[x][y][dir] + 1;
                Q.push({ndir, {x, y}});
            }
            //북
            int nx = x;
            int ny = y;
            for(int i=1;i<=3;i++){
                nx--;
                if(nx < 1)break;
                if(Matrix[nx][ny] == '1')break;
                if(visited[nx][ny][dir]){
                    if(D[nx][ny][dir] > D[x][y][dir] + 1){
                        D[nx][ny][dir] = D[x][y][dir] + 1;
                        Q.push({dir, {nx, ny}});
                    }
                }
                else{
                    visited[nx][ny][dir] = true;
                    D[nx][ny][dir] = D[x][y][dir] + 1;
                    Q.push({dir, {nx, ny}});
                }
            }
        }
    }
}

void Input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> Matrix[i][j];
        }
    }
    cin >> sx >> sy >> sdir;
    cin >> ex >> ey >> edir;
}

void Solution(){
    BFS();
    cout << D[ex][ey][edir];
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