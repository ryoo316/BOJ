#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#define Max 11
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int, int, int> t5;

int h, w;
char board[Max][Max];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int bfs(int rsx, int rsy, int bsx, int bsy){
    queue<t5> Q;
    bool visited[Max][Max][Max][Max] = {};
    visited[rsx][rsy][bsx][bsy] = 1;
    Q.push({rsx, rsy, bsx, bsy, 0});
    while(!Q.empty()){
        int rx, ry, bx, by, cnt;
        tie(rx, ry, bx, by, cnt) = Q.front();
        Q.pop();
        if(cnt > 10) continue;
        if(board[rx][ry] == 'O' && board[bx][by] != 'O'){
            return 1;
        }
        for(int i=0;i<4;i++){
            int rnx = rx, rny = ry, bnx = bx, bny = by;
            // 레드 구슬 움직이기
            while(true){
                rnx += dx[i];
                rny += dy[i];
                if(board[rnx][rny] == '#'){
                    rnx -= dx[i];
                    rny -= dy[i];
                    break;
                }
                else if(board[rnx][rny] == 'O')
                    break;
            }
            // 블루 구슬 움직이기
            bool flag = false;
            while(true){
                bnx += dx[i];
                bny += dy[i];
                if(board[bnx][bny] == '#'){
                    bnx -= dx[i];
                    bny -= dy[i];
                    break;
                }
                else if(board[bnx][bny] == 'O'){
                    flag = true;
                    break;
                }
            }
            // 서로 같은 좌표일 때
            if(rnx == bnx && rny == bny){
                if(board[rnx][rny] != 'O'){
                    int r_cnt = abs(rnx - rx) + abs(rny - ry);
                    int b_cnt = abs(bnx - bx) + abs(bny - by);
                    if(r_cnt > b_cnt){
                        rnx -= dx[i];
                        rny -= dy[i];
                    }
                    else{
                        bnx -= dx[i];
                        bny -= dy[i];
                    }
                }
            }
            // 만약 방문했던 좌표라면 continue
            if(visited[rnx][rny][bnx][bny]) continue;
            if(flag) continue;
            visited[rnx][rny][bnx][bny] = true;
            Q.push({rnx, rny, bnx, bny, cnt + 1});
        }
    }
    return 0;
}

void solve(){
    int rx, ry, bx, by;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        string inp;
        cin >> inp;
        for(int j=0;j<w;j++){
            board[i][j] = inp[j];
            if(board[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            else if(board[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }
    cout << bfs(rx, ry, bx, by);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--)
        solve();

    return 0;
}