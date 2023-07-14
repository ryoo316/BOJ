#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define Max 10011
#define MOD 10000
using namespace std;

const int INF = 0x3f3f3f3f;

typedef tuple<int, int, int, int, int> t5;

pair<int, char> route[Max] = {};

void bfs(int a, int b){
    queue<int> Q;
    int visited[Max] = {};
    Q.push(a);
    visited[a] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur == b) break;
        // D
        if(!visited[cur*2%MOD]){
            visited[cur*2%MOD] = true;
            Q.push(cur*2%MOD);
            route[cur*2%MOD].X = cur;
            route[cur*2%MOD].Y = 'D';
        }
        // S
        if(cur == 0){
            if(!visited[9999]){
                visited[9999] = true;
                Q.push(9999);
                route[9999].X = cur;
                route[9999].Y = 'S';
            }
        }
        else{
            if(!visited[cur-1]){
                visited[cur-1] = true;
                Q.push(cur-1);
                route[cur-1].X = cur;
                route[cur-1].Y = 'S';
            }
        }
        // L
        int l = cur, d = 0, c = 1;
        while(l >= 10){
            l /= 10;
            d = l % 10;
            c++;
        }
        if(c != 4)
            d = 0;
        l = cur;
        l *= 10;
        int ten = 1;
        for(int i=0;i<4;i++)
            ten *= 10;
        l %= ten;
        l += d;
        if(!visited[l]){
            visited[l] = true;
            Q.push(l);
            route[l].X = cur;
            route[l].Y = 'L';
        }
        // R
        int r = cur;
        d = r % 10;
        r /= 10;
        ten /= 10;
        d *= ten;
        r += d;
        if(!visited[r]){
            visited[r] = true;
            Q.push(r);
            route[r].X = cur;
            route[r].Y = 'R';
        }
    }
}

void Solve(){
    int a, b;
    cin >> a >> b;

    bfs(a, b);
    vector<char> ans;
    int idx = b;
    while(idx != a){
        ans.push_back(route[idx].Y);
        idx = route[idx].X;
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--)
        Solve();

    return 0;
}