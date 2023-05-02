#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

/*
    두 죄수가 지점 T에 만났다고 하면,
    결국 두 죄수가 지점 T까지 오는 최소 비용 C1와
    지점 T에서 밖으로 나가는 최소 비용 C2를 더한 값이 답이 된다.
*/

typedef pair<int, pair<int, int>> Edge;

int h, w;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

// 일반적인 다익스트라 함수(2차원 벡터 반환)
vector<vector<int>> Dijkstra(vector<string> Matrix, int sx, int sy){
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    vector<vector<int>> D(h, vector<int>(w, INF));
    D[sx][sy] = 0;
    Q.push({0, {sx, sy}});
    while(!Q.empty()){
        int cur_door_cnt = Q.top().first;
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();
        if(D[x][y] < cur_door_cnt) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next_door_cnt = cur_door_cnt;
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(Matrix[nx][ny] == '*') continue;
            if(Matrix[nx][ny] == '#') next_door_cnt++;
            if(D[nx][ny] > next_door_cnt){
                D[nx][ny] = next_door_cnt;
                Q.push({D[nx][ny], {nx, ny}});
            }
        }
    }
    return D;
}

void Solve(){
    cin >> h >> w;
    vector<string> V(h+2);
    for(int i=1;i<=h;i++){
        cin >> V[i];
        V[i] = '.' + V[i] + '.';//양 옆 빈 공간 추가
    }
    //크기가 키우기 (빈 공간)
    h += 2;
    w += 2;
    //위 아래 빈 공간 추가
    for(int i=0;i<w;i++){
        V[0] += '.';
        V[h-1] += '.';
    }
    int x1 = INF, y1 = INF, x2, y2;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(V[i][j] == '$'){
                // 1번 죄수
                if(x1 == INF && y1 == INF){
                    x1 = i;
                    y1 = j;
                }
                // 2번 죄수
                else{
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    vector<vector<int>> D1 = Dijkstra(V, 0, 0);// 감옥 밖에서
    vector<vector<int>> D2 = Dijkstra(V, x1, y1);// 1번 죄수
    vector<vector<int>> D3 = Dijkstra(V, x2, y2);// 2번 죄수
    int ans = INF;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(D1[i][j] == INF) continue;
            int sum = D1[i][j] + D2[i][j] + D3[i][j];
            //중간 지점이 '#'이면 중복이니 sum-2 해준다.
            if(V[i][j] == '#')
                sum -= 2;
            ans = min(ans, sum);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while(T--)
        Solve();

    return 0;
}