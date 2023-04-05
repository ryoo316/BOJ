#include<bits/stdc++.h>
#define Max 200001
using namespace std;

void Solve(){
    int n, k;
    vector<bool> visited(Max, 0);
    int route[Max] = {};

    cin >> n >> k;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur == k){
            break;
        }
        if(cur * 2 <= 200000 && !visited[cur * 2]){
            Q.push(cur * 2);
            visited[cur * 2] = true;
            route[cur * 2] = cur;
        }
        if(cur + 1 <= 100000 && !visited[cur + 1]){
            Q.push(cur + 1);
            visited[cur + 1] = true;
            route[cur + 1] = cur;
        }
        if(cur - 1 >= 0 && !visited[cur - 1]){
            Q.push(cur - 1);
            visited[cur - 1] = true;
            route[cur - 1] = cur;
        }
    }
    vector<int> ans;
    int idx = k;
    while(idx != n){
        ans.push_back(idx);
        idx = route[idx];
    }
    ans.push_back(n);
    cout << ans.size()-1 << "\n";
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}