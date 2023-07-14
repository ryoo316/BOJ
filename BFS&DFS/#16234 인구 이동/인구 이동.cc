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
#define Max 51
using namespace std;

const int INF = 0x3f3f3f3f;

int land[Max][Max];
bool visited[Max][Max];
int n, l, r;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool bfs(int sx, int sy){
    queue<pii> Q;
    vector<pii> V;

    visited[sx][sy] = true;
    Q.push({sx, sy});
    V.push_back({sx, sy});
    int sum_pop = land[sx][sy];

    while(!Q.empty()){
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int diff_pop = abs(land[nx][ny] - land[x][y]);// 두 나라 인구 차이
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(l > diff_pop || r < diff_pop) continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
            sum_pop += land[nx][ny];
            V.push_back({nx, ny});
        }
    }

    int res_pop = sum_pop / V.size();

    for(auto [x, y] : V){
        land[x][y] = res_pop;
    }

    return V.size() > 1;
}

void Solve(){
    cin >> n >> l >> r;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> land[i][j];
    int time = 0;
    while(true){
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]) continue;
                if(bfs(i, j))
                    flag = true;
            }
        }
        if(!flag) break;
        time++;
        memset(visited, 0, sizeof(visited));
    }
    cout << time << "\n";
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