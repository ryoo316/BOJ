#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define Max 4001
#define INF 1e9 + 7
using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, pair<int, bool>> Edge_w;

int n, m;
int fox[Max];
int wolf[2][Max];

vector<Edge> V[Max];

void Dijkstra_fox(int start){
    priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
    fox[start] = 0;
    Q.push({0, start});
    while(!Q.empty()){
        int dist = Q.top().first;
        int cur = Q.top().second;
        Q.pop();
        if(dist > fox[cur])continue;
        for(auto x : V[cur]){
            int nextv = x.first;
            int nextdist = dist + x.second;
            if(nextdist < fox[nextv]){
                fox[nextv] = nextdist;
                Q.push({nextdist, nextv});
            }
        }
    }
}

void Dijkstra_wolf(int start){
    priority_queue<Edge_w, vector<Edge_w>, greater<Edge_w>> Q;
    Q.push({0, {1, 1}});
    while(!Q.empty()){
        int dist = Q.top().first; 
        int cur = Q.top().second.first;
        int flag = Q.top().second.second;
        Q.pop();

        if(dist > wolf[(flag+1)%2][cur]) continue;
        for(auto x : V[cur]){
            int nextv = x.first;
            int nextdist = dist;
            if(flag)
                nextdist += x.second/2;//느리게
            else
                nextdist += x.second*2;//빠르게
            if(nextdist < wolf[flag][nextv]){
                wolf[flag][nextv] = nextdist;
                Q.push({nextdist, {nextv, (flag+1)%2}});
            }
        }
    }
}

void Input(){
    cin >> n >> m;
    while(m--){
        int a, b, d;
        cin >> a >> b >> d;
        d *= 2;
        V[a].push_back({b, d});
        V[b].push_back({a, d});
    }
}

void Solution(){
    for(int i=1;i<=n;i++){
        fox[i] = INF;
        wolf[0][i] = INF;//처음에 빨리
        wolf[1][i] = INF;//처음에 느리게
    }
    Dijkstra_fox(1);
    Dijkstra_wolf(1);
    int cnt = 0;
    for(int i=2;i<=n;i++)
        if(fox[i] < min(wolf[0][i], wolf[1][i]))
            cnt++;
    cout << cnt;
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