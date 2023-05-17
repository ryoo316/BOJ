#include<iostream>
#define Max 201
using namespace std;

void Solve(){
    int n;
    int dp[Max] = {};
    int a[Max] = {};
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int mx = 0;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }
    cout << n - mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}