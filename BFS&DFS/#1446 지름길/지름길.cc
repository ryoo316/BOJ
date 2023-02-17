#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Max 10001
using namespace std;

struct coord{
  int s;
  int e;
  int dist;
};

int n, d;

vector<coord> v; 
int ans[Max] = {};

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> d;
  for(int i=1;i<=n;i++){
    int s, e, l;
    cin >> s >> e >> l;
    v.push_back({s, e, l});
  }
}

void solve(){
  for(int i=1;i<=d;i++)
    ans[i] = i;
  for(int k=0;k<=d;k++){
    ans[k] = min(ans[k], ans[k-1] + 1);

    for(int i=0;i<v.size();i++){
      int s = v[i].s;
      int e = v[i].e;
      int dist = v[i].dist;
      if(k == s && e <= d && ans[e] > dist + ans[s])
        ans[e] = dist + ans[s];
    }
  }
}

int main(){
  input();
  solve();

  cout << ans[d];
  return 0;
}