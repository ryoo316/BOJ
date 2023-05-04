#include<bits/stdc++.h>
using namespace std;

void Solve(){
    int n, idx = 1;
    stack<int> S;
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a == idx)
            idx++;
        else
            S.push(a);
        while(!S.empty() && S.top() == idx){
            S.pop();
            idx++;
        }
    }
    while(!S.empty()){
        if(S.top() == idx){
            S.pop();
            idx++;
        }
        else{
            cout << "Sad\n";
            return;
        }
    }
    cout << "Nice\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}