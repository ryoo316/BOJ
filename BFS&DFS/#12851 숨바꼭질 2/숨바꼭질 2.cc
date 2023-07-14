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
#define Max 100001
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int, int, int> t5;

pii bfs(int start, int end){
    queue<pii> Q;
    bool visited[Max] = {};
    int find_time = INF;
    int cnt = 0;
    
    Q.push({start, 0});
    visited[start] = true;

    while(!Q.empty()){
        int cur, time;
        tie(cur, time) = Q.front();
        Q.pop();
        visited[cur] = true;
        if(find_time < time) break;
        if(cur == end){
            if(find_time == INF){
                find_time = time;
                cnt++;
            }
            else if(find_time == time)
                cnt++;
        }
        int d[] = {cur*2, cur+1, cur-1};
        for(int i=0;i<3;i++){
            if(d[i] < 0 || d[i] > 100000) continue;

            if(visited[d[i]]) continue;
            Q.push({d[i], time + 1});
        }
    }
    return {find_time, cnt};
}


void Solve(){
    int n, k;
    cin >> n >> k;
    
    if(n == k){
        cout << 0 << "\n" << 1;
        return;
    }

    pii ans = bfs(n, k);
    cout << ans.X << "\n" << ans.Y;
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