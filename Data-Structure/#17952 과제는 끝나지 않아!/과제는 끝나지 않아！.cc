#include<bits/stdc++.h>
using namespace std;

void Solve(){
    int n, ans = 0;
    cin >> n;
    stack<pair<int, int>> S;
    while(n--){
        int a;
        cin >> a;
        if(a == 1){
            int s, t;
            cin >> s >> t;
            if(t - 1 == 0)
                ans += s;
            else
                S.push({s, t - 1});
        }
        else if(!S.empty()){
            int curscore = S.top().first;
            int curtime = S.top().second;
            S.pop();
            if(curtime - 1 == 0)
                ans += curscore;
            else
                S.push({curscore, curtime - 1});
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}