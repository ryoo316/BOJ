#include<bits/stdc++.h>
using namespace std;

void Solve(){
    stack<int> S;
    int n;
    long long cnt = 0;
    cin >> n;
    S.push(1000000001);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(i == 1){ 
            S.push(x);
            continue;
        }
        while(S.top() <= x)
            S.pop();
        cnt += S.size() - 1;
        S.push(x);
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}