#include<bits/stdc++.h>
using namespace std;

void Solve(){
    deque<int> DQ;
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        DQ.push_back(i);
    while(m--){
        deque<int> LD;
        deque<int> RD;
        LD = DQ;
        RD = DQ;
        int a;
        bool flag = false;
        cin >> a;//2 9 5
        if(a == DQ.front()){
            DQ.pop_front();
        }
        else{
            for(;;){
                if(a == RD.front()){
                    flag = true;
                    break;
                }
                if(a == LD.front()){
                    break;
                }
                int v1 = LD.front(), v2 = RD.back();
                LD.pop_front();
                RD.pop_back();
                LD.push_back(v1);
                RD.push_front(v2);
                cnt++;
            }
        }
        if(flag)
            DQ = RD;
        else
            DQ = LD;
        DQ.pop_front();
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