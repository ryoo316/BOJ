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
#define Max 101
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int, int, int> t5;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int h, w;
int cheese_cnt = 0;
int board[Max][Max];

int bfs(){
    queue<pii> Q;
    int time = 0;

    while(true){
        int cnt[Max][Max] = {};
        bool visited[Max][Max] = {};
        Q.push({0, 0});
        visited[0][0] = true;
        while(!Q.empty()){
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(visited[nx][ny]) continue;
                if(board[nx][ny] == 1){
                    cnt[nx][ny]++;
                    if(cnt[nx][ny] == 2){
                        visited[nx][ny] = true;
                        board[nx][ny] = 0;
                        cheese_cnt--;
                    }
                }
                else if(board[nx][ny] == 0){
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
        time++;
        if(cheese_cnt == 0)
            break;
    }
    return time;
}

void Solve(){
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                cheese_cnt++;
        }
    }
    cout << (cheese_cnt == 0 ? 0:bfs());
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