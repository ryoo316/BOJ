#include<stdio.h>
#include<queue>
#include<vector>
#define INF 200001
using namespace std;

int v,e,k;

vector<pair<int, int> > a[20001];
int d[20001] = {};

void dijkstra(int start){
  d[start] = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, start));
  
  while(!q.empty()){
    int cur = q.top().second;
    int dist = -q.top().first;//짧은 것이 먼저 오도록 음수화한다.
    q.pop();
    if(d[cur] < dist)continue;
    for(int i=0;i<a[cur].size();i++){
      int next = a[cur][i].second;
      int nextdist = dist + a[cur][i].first;
      if(nextdist < d[next]){
        d[next] = nextdist;
        q.push(make_pair(-nextdist, next));
      }
    }
  }
}

int main(){
  scanf("%d %d %d",&v,&e,&k);
  for(int i=1;i<=v;i++){
    d[i] = INF;
  }
  for(int i=0;i<e;i++){
    int start, end, f;
    scanf("%d %d %d",&start,&end,&f);
    a[start].push_back(make_pair(f, end));
  }
  dijkstra(k);
  for(int i=1;i<=v;i++){
    if(d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n",d[i]);
  }
}