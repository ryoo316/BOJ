#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define Max 11
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int, int, int> t5;

char board[Max][Max];
int n, m;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(int rsx, int rsy, int bsx, int bsy){
    queue<t5> Q;
    bool visited[Max][Max][Max][Max] = {};
    int res = -1;

    visited[rsx][rsy][bsx][bsy] = true;
    Q.push({rsx, rsy, bsx, bsy, 0});

    while(!Q.empty()){
        int rx, ry, bx, by, cnt;
        tie(rx, ry, bx, by, cnt) = Q.front();
        Q.pop();
        if(board[rx][ry] == 'O' && board[bx][by] != 'O'){// 구멍에 빠졌으면 끝내기
            res = cnt;
            break;
        }
        if(cnt > 10) break;// 움직인 횟수가 10번 넘으면 끝내기
        for(int i=0;i<4;i++){
            int next_rx = rx;
            int next_ry = ry;
            int next_bx = bx;
            int next_by = by;

            while(true){
                next_rx += dx[i];
                next_ry += dy[i];
                if(board[next_rx][next_ry] == '#'){
                    next_rx -= dx[i];
                    next_ry -= dy[i];
                    break;
                }
                else if(board[next_rx][next_ry] == 'O')
                    break;
            }

            bool flag = false;
            while(true){
                next_bx += dx[i];
                next_by += dy[i];
                if(board[next_bx][next_by] == '#'){
                    next_bx -= dx[i];
                    next_by -= dy[i];
                    break;
                }
                else if(board[next_bx][next_by] == 'O'){
                    flag = true;
                    break;
                }
            }

            if(next_rx == next_bx && next_ry == next_by){// 같은 위치일 때
                if(board[next_rx][next_ry] != 'O'){// 구멍에 동시에 빠지지 않을 때
                    int r_cnt = abs(next_rx - rx) + abs(next_ry - ry);
                    int b_cnt = abs(next_bx - bx) + abs(next_by - by);
                    if(r_cnt < b_cnt){
                        next_bx -= dx[i];
                        next_by -= dy[i];
                    }
                    else{
                        next_rx -= dx[i];
                        next_ry -= dy[i];
                    }
                }
            }

            if(visited[next_rx][next_ry][next_bx][next_by]) continue;
            if(flag) continue;
            visited[next_rx][next_ry][next_bx][next_by] = true;
            Q.push({next_rx, next_ry, next_bx, next_by, cnt + 1});
        }
    }
    return res;
}

void Solve(){
    int rx = 0, ry = 0, bx = 0, by = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string inp;
        cin >> inp;
        for(int j=0;j<m;j++){
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
    int ans = bfs(rx, ry, bx, by);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--)
        Solve();

    return 0;
}