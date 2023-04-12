#include<bits/stdc++.h>
#define Max 101
#define INF 1e9 + 7
using namespace std;

int n, m;
int path[Max][Max];
int dist[Max][Max];
vector<int> V;

void findPath(int s, int e){
    if(path[s][e] == 0){
        V.push_back(s);
        V.push_back(e);
        return;
    }
    findPath(s, path[s][e]);
    V.pop_back();
    findPath(path[s][e], e);
}

void Solve(){
    cin >> n >> m;
    //거리 행렬 초기화
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = INF;
        }
    }
    while(m--){
        int s, e, c;
        cin >> s >> e >> c;
        dist[s][e] = min(dist[s][e], c);
    }
    for(int k=1;k<=n;k++){
        for(int s=1;s<=n;s++){
            for(int e=1;e<=n;e++){
                if(s == e) continue;
                if(dist[s][e] > dist[s][k] + dist[k][e]){
                    dist[s][e] = dist[s][k] + dist[k][e];
                    path[s][e] = k;//s -> e를 가기위해 거친 k
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INF){
                cout << 0 << "\n"; 
                continue;
            }
            vector<int> tmp;
            V = tmp;//벡터 초기화
            findPath(i, j);//i -> j 경로
            cout << V.size() << " ";
            for(auto x : V)
                cout << x << " ";
            cout << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}