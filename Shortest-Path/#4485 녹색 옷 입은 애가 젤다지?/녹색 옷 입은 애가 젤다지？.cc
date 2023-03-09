#include<iostream>
#include<queue>
#include<cstring>
#define Max 126
#define INF 1e9
using namespace std;

typedef pair<int, pair<int, int>> v;

int n, c = 1;
int Matrix[Max][Max] = {};
int money[Max][Max] = {};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void Init(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      money[i][j] = INF;
    }
  }
}

void BFS(){
  priority_queue<v, vector<v>, greater<v>> Q;
  Q.push({Matrix[1][1], {1, 1}});
  while(!Q.empty()){
    int cnt = Q.top().first;
    int x = Q.top().second.first;
    int y = Q.top().second.second;
    Q.pop();
    if(money[x][y] < cnt)continue;
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
      int nextmoney = cnt + Matrix[nx][ny];
      if(nextmoney < money[nx][ny]){
        money[nx][ny] = nextmoney;
        Q.push({money[nx][ny], {nx, ny}});
      }
    }
  }
}

void Input(){
  cin >> n;
  if(n == 0)
    exit(0);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> Matrix[i][j];
    }
  }
}

void Solution(){
  BFS();
  cout << "Problem " << c << ": " << money[n][n] << "\n";
}

void Solve(){
  Input();
  Init();
  Solution();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(1){
    Solve();
    c++;
  }
    
  return 0;
}
