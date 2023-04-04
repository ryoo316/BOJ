#include<bits/stdc++.h>
#define Max 1000001
using namespace std;

void Solve(){
    int f, s, e, u, d;
    cin >> f >> s >> e >> u >> d;
    vector<bool> visited(Max, 0);
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    int cnt = 0;
    while(!Q.empty()){
        int qsize = Q.size();
        cnt++;
        for(int i=0;i<qsize;i++){
            int cur = Q.front();
            Q.pop();
            if(cur == e){
                cout << cnt - 1;
                return;
            }
            if(cur + u <= f && !visited[cur + u]){
                Q.push(cur + u);
                visited[cur + u] = true;
            }
            if(cur - d > 0 && !visited[cur - d]){
                Q.push(cur - d);
                visited[cur - d] = true;
            }
        }
    }
    cout << "use the stairs";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}