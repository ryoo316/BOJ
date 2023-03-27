#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define Max 100001
#define INF 1e13 + 7
using namespace std;

typedef pair<long long, int> Edge;

int n, m, k, S;
int p, q;
int arr[Max];
long long D[Max];
bool dangercity[Max];
bool do_not_enter[Max];

vector<int> V[Max];

void BFS(int start){
    queue<pair<int, int>> Q;
    vector<bool> visited(Max, 0);
    Q.push({start, 0});
    while(!Q.empty()){
        int cur = Q.front().first;
        int s = Q.front().second;
        Q.pop();
        for(auto x : V[cur]){
            if(visited[x])continue;
            if(s + 1 > S)continue;
            Q.push({x, s+1});
            visited[x] = true;
        }
    }
    for(int i=1;i<=n;i++)
        if(visited[i] && !dangercity[i])
            dangercity[i] = true;
}

void Dijkstra(int start){
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    D[start] = 0;
    Q.push({0, start});
    while(!Q.empty()){
        long long dist = Q.top().first;
        int cur = Q.top().second;
        Q.pop();
        if(dist > D[cur])continue;
        for(auto x : V[cur]){
            if(do_not_enter[x])continue;
            long long nextdist = dist;
            if(dangercity[x])
                nextdist += q;
            else
                nextdist += p;
            if(nextdist < D[x]){
                D[x] = nextdist;
                Q.push({nextdist, x});
            }
        }
    }
}

void Input(){
    cin >> n >> m >> k >> S;
    cin >> p >> q;
    for(int i=1;i<=k;i++)
        cin >> arr[i];
    while(m--){
        int s, e;
        cin >> s >> e;
        V[s].push_back(e);
        V[e].push_back(s);
    }
}

void Solution(){
    for(int i=1;i<=k;i++){
        do_not_enter[arr[i]] = true;
        BFS(arr[i]);
    }
    for(int i=1;i<=n;i++)
        D[i] = INF;
    Dijkstra(1);
    cout << (dangercity[n] ? D[n] - q : D[n] - p);
}

void Solve(){
    Input();
    Solution();
}

int main(){
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}