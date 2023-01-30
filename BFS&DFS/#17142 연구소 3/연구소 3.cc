#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define Max 51
using namespace std;

//structure
typedef struct COORD{
  int x;
  int y;
}coord;

//up, down, left, right
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//Size of Lab, Number of virus, Minimum time
int n, m, min_time = 999999090, empty_area = 0, temp;

//Lab map Array
int Matrix[Max][Max] = {};
//visited_check Array
int visited[Max][Max] = {};
//Array to check if virus in released
int virus_check[Max][Max] = {};

//virus vector
vector<coord> v;

//BFS execution function
int BFS(){
  int time = 0;
  queue<coord> a;
  //insert the virus location into the queue
  for(int i=0;i<v.size();i++){
    a.push({v[i].x, v[i].y});
    visited[v[i].x][v[i].y] = 0;
  }
  while(!a.empty()){
    coord now = a.front();
    int x = now.x;
    int y = now.y;
    a.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
      if(visited[nx][ny] != -1)continue;
      if(Matrix[nx][ny] == 0){//If the surrounding area is empty place, the virus spreads
        a.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
        empty_area--;
      }
      else if(Matrix[nx][ny] == 2){
        if(empty_area == 0)continue;
        a.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(visited[i][j] > time)
        time = visited[i][j];
    }
  }
  return time;
}

//Function to determine if the virus has spread throughout the lab
int virus_spread(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(Matrix[i][j] == 0 && visited[i][j] == -1)
        return 0;
    }
  }
  return 1;
}

//Functions that activate viruses
void virus(int x, int y, int cnt){
  //If put all virus
  if(cnt == m){
    memset(visited, -1, sizeof(visited));
    empty_area = temp;
    int res = BFS();
    if(virus_spread()){
      if(min_time > res)
        min_time = res;
    }
  }
  for(int i=x;i<=n;i++){
    for(int j=y;j<=n;j++){
      if(Matrix[i][j] != 2 || virus_check[i][j] == 1)continue;
      //activate virus
      v.push_back({i, j});
      virus_check[i][j] = 1;
      virus(i, j, cnt + 1);
      v.pop_back();
      virus_check[i][j] = 0;
    }
    y=1;
  }
}

int main(){
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> Matrix[i][j];
      if(Matrix[i][j] == 0)
        empty_area++;
    }
  }
  temp = empty_area;
  virus(1,1,0);
  if(min_time == 999999090)
    cout << -1;
  else
    cout << min_time;
}