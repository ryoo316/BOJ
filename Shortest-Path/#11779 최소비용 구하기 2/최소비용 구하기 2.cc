#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 1001;
constexpr auto INF = 1e9 + 7;
using namespace std;

typedef pair<int, int> v;

int n, m, sv, ev;
int D[Max] = {};
int Route[Max];

vector<pair<int, int>> V[Max];

void Dijkstra(int start){
    priority_queue<v, vector<v>, greater<v>> Q;
    D[start] = 0;
    Q.push({0, start});
    while(!Q.empty()){
        int dist = Q.top().first;
        int curv = Q.top().second;
        Q.pop();
        if(dist > D[curv])continue;
        for(auto x : V[curv]){
            int nextv = x.first;
            int nextdist = dist + x.second;
            if(D[nextv] > nextdist){
                D[nextv] = nextdist;
                Route[nextv] = curv;
                Q.push({D[nextv], nextv});
            }
        }
    }
}

void Input(){
    cin >> n >> m;
    while(m--){
        int s, e, c;
        cin >> s >> e >> c;
        V[s].push_back({e, c});
    }
    cin >> sv >> ev;
}

void Solution(){
    for(int i=1;i<=n;i++)
        D[i] = INF;
    Dijkstra(sv);
    cout << D[ev] << "\n";
    vector<int> ans;
    int idx = ev;
    while(idx != sv){
        ans.push_back(idx);
        idx = Route[idx];
    }
    ans.push_back(sv);
    cout << ans.size() << "\n";
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << " ";
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