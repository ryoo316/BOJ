#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct coord{
  int x;
  int y;
  int b;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    queue<coord> q;
    vector<pair<int, int>> v;
    int n, ex, ey, sx, sy;
    cin >> n;
    int px, py;
    cin >> sx >> sy;
    for(int i=1;i<=n;i++){
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    cin >> ex >> ey;
    sort(v.begin(), v.end());

    q.push({sx, sy, 20});
    bool visited[103] = {};
    int flag = 1;
    while(!q.empty()){
      coord cur = q.front();
      int x = cur.x;
      int y = cur.y;
      int beer = cur.b;
      q.pop();
      int c1 = (abs(ex - x) + abs(ey - y))%50 > 0 ? 1:0;
      if((abs(ex - x) + abs(ey - y))/50 + c1 <= beer){
        cout << "happy";
        flag = 0;
        while(!q.empty())
          q.pop();
        continue;
      }
      for(int i=0;i<n;i++){
        int vx = v[i].first;
        int vy = v[i].second;
        if(visited[i])continue;
        int c2 = (abs(vx - x) + abs(vy - y))%50 > 0 ? 1:0; 
        if((abs(vx - x) + abs(vy - y))/50 + c2 <= beer){
          q.push({vx, vy, 20});
          visited[i] = true;
        }
      }
    }
    if(flag)
      cout << "sad";
    cout << "\n";
  }
  return 0;
}