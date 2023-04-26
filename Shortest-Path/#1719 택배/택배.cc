#include<bits/stdc++.h>
#define Max 201
#define INF 1e9 + 7
using namespace std;

int n, m;
int dist[Max][Max];
int path[Max][Max];

void PrintPath(int s, int e){
    if(path[s][e] == 0){
        cout << e << " ";
        return;
    }
    PrintPath(s, path[s][e]);
}

void Solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = INF;
        }
    }
    while(m--){
        int s, e, c;
        cin >> s >> e >> c;
        dist[s][e] = min(dist[s][e], c);
        dist[e][s] = min(dist[e][s], c);
    }
    for(int k=1;k<=n;k++){
        for(int s=1;s<=n;s++){
            for(int e=1;e<=n;e++){
                if(dist[s][e] > dist[s][k] + dist[k][e]){
                    dist[s][e] = dist[s][k] + dist[k][e];
                    path[s][e] = k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                cout << "- ";
                continue;
            }
            PrintPath(i, j);
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}