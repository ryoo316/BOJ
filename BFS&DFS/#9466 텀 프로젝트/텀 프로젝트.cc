#include<iostream>
#include<vector>
#include<cstring>
#define Max 100001
using namespace std;

int n;
bool visited[Max] = {};
bool finished[Max] = {};//그 원소를 대상으로 한 DFS가 끝났는지
int P[Max] = {};//기록
int cyc = 0;//사이클 정점 수

vector<int> adj[Max];

void Init(){
  for(int i=1;i<=n;i++)
    adj[i].clear();
  memset(visited, 0, sizeof(visited));
  memset(P, 0, sizeof(P));
  memset(finished, 0, sizeof(finished));
  cyc = 0;
}

void DFS(int start){
  visited[start] = true;      //방문체크
  for(int nextv : adj[start]){//다음 정점
    if(!visited[nextv]){
      P[start] = nextv;//기록해준다. sv -> nv
      DFS(nextv);
    }
    else if(!finished[nextv]){
      for(int i=nextv;i!=start;i = P[i])//사이클에 포함된 정점들을 세어준다.
        cyc++;
      cyc++;//자기자신
    }
  }
  finished[start] = true;//이 원소를 대상으로 한 DFS가 끝났다고 표시
}

void Input(){
  cin >> n;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    adj[i].push_back(a);
  }
}

void Solution(){
  for(int i=1;i<=n;i++){
    if(visited[i])continue;
    DFS(i);
  }
  cout << n - cyc << "\n";//정점의 수 - 사이클 정점의 수가 답이다.
}

void Solve(){
  Input();
  Solution();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    Solve(); //문제 풀기
    Init();  //다음 테케를 위해 초기화
  }

  return 0;
}