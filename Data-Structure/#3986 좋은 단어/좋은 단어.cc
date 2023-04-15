#include<bits/stdc++.h>
using namespace std;

void Solve(){
    int n, cnt = 0;
    cin >> n;
    while(n--){
        stack<char> s;
        string str;
        cin >> str;
        for(auto c : str){
            //스택이 비어있지않고 탑과 c값이 같으면 pop
            if(!s.empty() && s.top() == c) s.pop();
            else s.push(c);
        }
        if(s.empty())
            cnt++;
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