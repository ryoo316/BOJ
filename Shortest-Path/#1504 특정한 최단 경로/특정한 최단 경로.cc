#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 12345678
using namespace std;

int v,e,k;
int v1,v2;
int sv1,sv2;
int v1v2,v1v,v2v;

vector<pair<int, int> > adj[801];
int d[801] = {};

void dijkstra(int start){
  for(int i=0;i<=v;i++){
    d[i] = INF;
  }
  d[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(make_pair(0, start));
  
  while(!q.empty()){
    int cur = q.top().second;
    int dist = q.top().first;
    q.pop();
    if(d[cur] < dist)continue;
    for(int i=0;i<adj[cur].size();i++){
      int next = adj[cur][i].first;
      int nextdist = dist + adj[cur][i].second;
      if(nextdist < d[next]){
        d[next] = nextdist;
        q.push(make_pair(nextdist, next));
      }
    }  
  }
}

int main(){
  scanf("%d %d",&v,&e);
  
  for(int i=0;i<e;i++){
    int start, end, f;
    scanf("%d %d %d",&start,&end,&f);
    adj[start].push_back({end, f});
    adj[end].push_back({start, f});
  }
  scanf("%d%d",&v1,&v2);


  //start -> v1 -> v2 -> N
  //start -> v2 -> v1 -> N
  //다익스트라 함수 세번 실행
  //s -> v1, s -> v2
  dijkstra(1);
  sv1 = d[v1];
  sv2 = d[v2];
  //v1 -> v2, v1 -> v
  dijkstra(v1);
  v1v2 = d[v2];
  v1v = d[v];
  //v2 -> v
  dijkstra(v2);
  v2v = d[v];
  int ans = INF;

  //두 경로중 짧은 경로
  ans = min(ans, sv1 + v1v2 + v2v);
  ans = min(ans, sv2 + v1v2 + v1v);
  if(v1v2 >= INF || ans >= INF)
    printf("-1");
  else
    printf("%d",ans);
}