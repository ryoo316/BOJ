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
#define Max 17
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int> t3;

const int dx[4] = {0,-1,0,1};
const int dy[4] = {-1,0,1,0};

int h, w, d, mx = -1;
bool archer_check[Max];
int board[Max][Max];
vector<pii> archer_coord;

int bfs(){
    int board_copy[Max][Max] = {};
    int enemy_cnt = 0;
    int eliminated = 0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            board_copy[i][j] = board[i][j];
            if(board[i][j])
                enemy_cnt++;
        }
    }

    while(enemy_cnt){
        vector<pii> del;// 제거할 적
        for(auto [sx, sy] : archer_coord){
            bool visited[Max][Max] = {};
            queue<t3> Q;

            Q.push({sx, sy, 0});
            visited[sx][sy] = true;
            bool is_find = false;// 제거할 적을 찾았는지

            while(!Q.empty()){
                if(is_find) break;// 제거할 적을 찾으면 큐에서 나간다.
                int x, y, dist;
                tie(x, y, dist) = Q.front();
                Q.pop();
                if(dist + 1 > d) continue;
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                    if(visited[nx][ny]) continue;
                    if(board_copy[nx][ny]){// 제거할 적의 좌표 저장
                        del.push_back({nx, ny});
                        is_find = true;
                        break;
                    }
                    else{
                        visited[nx][ny] = true;
                        Q.push({nx, ny, dist+1});
                    }
                }
            }
        }
        /*
            여러 궁수가 한 적을 공격하는 것을 구현하기 위해
            del이라는 제거할 적의 좌표를 저장하는 벡터를 선언
            벡터를 순회해서 한 적을 여러번 잡는 불상사를 제거한다.
        */
        for(auto [x, y] : del){
            if(board_copy[x][y]){
                board_copy[x][y] = 0;
                eliminated++;
                enemy_cnt--;
            }
        }

        // 적이 아래로 내려가는 것을 구현하는 반복문
        for(int i=h-1;i>=0;i--){
            for(int j=0;j<w;j++){
                if(i == h-1){
                    if(board_copy[i][j]){
                        board_copy[i][j] = 0;
                        enemy_cnt--;
                    }
                }
                else{
                    if(board_copy[i][j]){
                        board_copy[i][j] = 0;
                        board_copy[i+1][j] = 1;
                    }
                }
            }
        }
    }

    return eliminated;
}

// 궁수 위치 잡기(백트래킹) -> 15C3
void place_archer(int cnt){
    if(cnt == 3){
        mx = max(mx, bfs());
        return;
    }
    for(int i=0;i<w;i++){
        if(archer_check[i]) continue;
        archer_check[i] = true;
        archer_coord.push_back({h, i});
        place_archer(cnt + 1);
        archer_coord.pop_back();
        archer_check[i] = false;
    }
}

void Solve(){
    cin >> h >> w >> d;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin >> board[i][j];

    place_archer(0);
    cout << mx;
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