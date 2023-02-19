#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#define Max 101
using namespace std;

struct coord{
  int x;
  int y;
};

//행, 열
int h, w;

char Matrix[Max][Max] = {}; //맵 배열
int key = 0;                //열쇠 유무
bool visited[Max][Max] = {};//방문 체크

vector<int> V;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS(){
  queue<coord> Q;
  //밖에 큐 넣어주기(상근이는 밖에서 진입하니)
  for(int i=0;i<=w+1;i++){
    Q.push({0, i});
    Q.push({h+1, i});
  }
  for(int i=1;i<=h;i++){
    Q.push({i, 0});
    Q.push({i, w+1});
  }
  queue<coord> door[27];//열지못한 문들
  int ans = 0;
  while(!Q.empty()){
    coord cur = Q.front();
    int x = cur.x;
    int y = cur.y;
    Q.pop();
    visited[x][y] = true;
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w)continue;
      if(Matrix[nx][ny] == '*')continue;
      if(visited[nx][ny])continue;
      
      else if(Matrix[nx][ny] == '$')//문서가 있을 때
        ans++;
      else if('a' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'z'){//열쇠가 있을 때
        key |= 1 << (Matrix[nx][ny] - 'a');//열쇠를 얻는다
        while(!door[Matrix[nx][ny] - 'a'].empty()){//그 열쇠에 대한 문이 있으면 그 문 위치를 큐에 넣어주기
          coord doornow = door[Matrix[nx][ny] - 'a'].front();
          int x1 = doornow.x;
          int y1 = doornow.y;
          door[Matrix[nx][ny] - 'a'].pop();
          Q.push({x1, y1});
        }
      }
      else if('A' <= Matrix[nx][ny] && Matrix[nx][ny] <= 'Z'){//문이 있을때
        if(((1 << (Matrix[nx][ny] - 'A')) & key) == 0){
          door[Matrix[nx][ny] - 'A'].push({nx, ny});
          continue;
        }
      }
      visited[nx][ny] = true;
      Q.push({nx, ny});
    }
  }
  return ans;
}

void Input(){
  cin >> h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> Matrix[i][j];
    }
  }
  key = 0;
  string inp;
  cin >> inp;
  if(inp != "0"){
    for(int i=0;i<inp.size();i++){
      key |= (1 << (inp[i] - 'a'));
    }
  }
}

void Solution(){
  memset(visited, 0, sizeof(visited));
  V.push_back(BFS());
}

void Solve(){
  Input();
  Solution();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while(t--){
    Solve();
  }

  for(int i=0;i<V.size();i++)
    cout << V[i] << "\n";
  return 0;
}