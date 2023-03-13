#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
constexpr auto Max = 101;
constexpr auto INF = 1e9 + 7;
using namespace std;

typedef pair<int, int> v;

int n, m;
int visited[Max] = {};

vector<int> V[Max];

int BFS(int start){
    queue<v> Q;
    int cnt = 0;
    Q.push({start, 0});
    visited[start] = true;
    while(!Q.empty()){
        int cur = Q.front().first;
        int depth = Q.front().second;
        cnt += depth;
        Q.pop();
        for(auto x : V[cur]){
            int nextv = x;
            if(visited[nextv])continue;
            Q.push({nextv, depth + 1});
            visited[nextv] = true;
        }
    }
    return cnt;
}

void Input(){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
}

void Solution(){
    int mn = INF;
    int ans = 0;
    for(int i=n;i>=1;i--){
        memset(visited, 0, sizeof(visited));
        int val = BFS(i);
        if(mn >= val){
            mn = val;
            ans = i;
        }
    }
    cout << ans;
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