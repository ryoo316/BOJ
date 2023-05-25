#include<iostream>
#include<vector>
#include<deque>
#define Max 1001
#define pii pair<int, int>
using namespace std;

deque<pii> dq;

void Solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int inp;
        cin >> inp;
        dq.push_back({inp, i});
    }
    vector<int> ans;
    while(!dq.empty()){
        int cnt = dq.front().first;
        ans.push_back(dq.front().second);
        dq.pop_front();
        if(cnt > 0){
            // 현재 풍선을 pop해서 왼쪽으로 1칸씩 회전된 상태
            // 그러므로 cnt-1만큼 왼쪽으로 회전
            for(int i=0;i<cnt-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            // 현재 풍선을 pop했지만 오른쪽 회전할 거니 상관없음
            // 그러므로 cnt만큼 오른쪽으로 회전
            for(int i=cnt;i<0;i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    for(int x : ans)
        cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}