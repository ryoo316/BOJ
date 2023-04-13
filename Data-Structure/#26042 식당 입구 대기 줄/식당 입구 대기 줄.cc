#include<bits/stdc++.h>
#define Max 100001
using namespace std;

void Solve(){
    int n, mx_size = 0, back_mn = 1e9 + 7;
    cin >> n;
    queue<int> Q;
    
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            int c;
            cin >> c;
            Q.push(c);
            if(mx_size < Q.size()){
                mx_size = Q.size();
                back_mn = Q.back();
            }
            else if(mx_size == Q.size())
                back_mn = min(Q.back(), back_mn);
        }
        else
            Q.pop();
    }
    cout << mx_size << " " << back_mn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}