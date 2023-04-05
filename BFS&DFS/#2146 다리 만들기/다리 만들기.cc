#include<bits/stdc++.h>
#define Max 101
using namespace std;

//지도의 크기
int n;
//기본 지도 행렬
int Matrix[Max][Max];
//섬을 그룹화한다.
int group[Max][Max];
//섬에서부터 임의의 x, y좌표까지의 거리
int dist[Max][Max];
//그룹, 가장 짧은 다리길이
int g = 0, min_val = 99999999;

//그룹화할때 방문체크용
bool visited[Max][Max];

//상 하 좌 우 탐색 함수
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//그룹화하는 함수
void group_BFS(int x, int y){
    queue<pair<int, int>> Q;
    Q.push({x, y});
    visited[x][y] = true;
    group[x][y] = g;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
            if(visited[nx][ny])continue;
            if(!Matrix[nx][ny])continue;
            visited[nx][ny] = true;
            group[nx][ny] = g;
            Q.push({nx, ny});
        }
    }
}

void find_bridge(){
    queue<pair<int, int>> Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Matrix[i][j]){
                bool is_possible = false;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
                    if(Matrix[nx][ny] == 0)
                        is_possible = true;               
                }
                //주변에 바다가 없으면 continue
                if(!is_possible)continue;
                Q.push({i, j});
            }
        }
    }
    bool is_find = false;
    while(!Q.empty()){
        if(is_find)break;//이미 찾았다면 나가기
        int qsize = Q.size();
        for(int i=0;i<qsize;i++){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                //범위 벗어나면 continue
                if(nx < 1 || ny < 1 || nx > n || ny > n)continue;
                //섬이면 continue
                if(Matrix[nx][ny])continue;
                //같은 그룹이면 continue
                if(group[nx][ny] == group[x][y])continue;
                /*
                    다른 그룹이고
                    대상 그룹이 0이 아니라면(섬에서 퍼진것이면)
                    다리만들기
                */
                if(group[nx][ny] != group[x][y] && group[nx][ny]){
                    //최소값 갱신
                    min_val = min(min_val, dist[nx][ny] + dist[x][y]);
                    //이 큐사이즈만큼 반복하고 끝나게 true
                    is_find = true;
                    continue;
                }
                Q.push({nx, ny});
                group[nx][ny] = group[x][y];
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

void Solve(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> Matrix[i][j];
    
    //그룹화하는 반복문
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j])continue;
            if(!Matrix[i][j])continue;
            g++;
            group_BFS(i, j);
        }
    }
    find_bridge();//가장 짧은 다리찾기
    cout << min_val;//답 출력
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}