#include<iostream>
#include<queue>
constexpr auto Max = 101;
constexpr auto INF = 1e9 + 7;
using namespace std;

/*
* 백준 6087 레이저 통신
같은 좌표에 도달하더라도 방향이 다르면 다른 경우라 생각해야한다.
방향에 따라 거울의 필요 여부가 달라진다.
따라서 방향을 저장하는 3차원 배열이 필요하다.
이전에 방문했더라도 다시 방문하는 경우가 있다
다시 방문했는데 거울의 값이 이번 값이 더 작으면
갱신시켜줘야한다.
*/

//순서대로 이전 방향, x 좌표, y 좌표 
typedef pair<int, pair<int, int>> v;

//높이, 너비, 'C'의 시작좌표, 'C'의 목표좌표
int h, w, sx = 0, sy = 0, ex, ey;
//최소 거울의 개수 저장하는배열
int D[Max][Max][4] = {};
//방문체크 (방향도 체크한다)
bool visited[Max][Max][4] = {};
//기본 맵 2차원 행렬
char Matrix[Max][Max] = {};

//상 하 좌 우 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int startx, int starty) {
	queue<v> Q;//큐
	
	for (int i = 0; i < 4; i++) {
		visited[startx][starty][i] = true;
		D[startx][starty][i] = 0;//시작 좌표의 거울의 개수는 0
	}
	Q.push({-1, {startx, starty} });
	while (!Q.empty()) {
		int dir = Q.front().first;//이전 방향
		int x = Q.front().second.first;  //x 좌표
		int y = Q.front().second.second; //y 좌표
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > h || ny > w)continue;
			if (Matrix[nx][ny] == '*')continue;//벽이면 continue
			if (dir == i) {//이전 방향과 같은 방향이면
				if (visited[nx][ny][i]) {
					//방문했었는데 최소 거울 갱신이 가능하면 갱신하고 큐에다 넣기
					if (D[nx][ny][i] > D[x][y][dir]) {
						D[nx][ny][i] = D[x][y][dir];//갱신
						Q.push({ i, {nx, ny} });
					}
				}
				else {
					D[nx][ny][i] = D[x][y][dir];//거울 설치
					visited[nx][ny][i] = true;
					Q.push({ i, {nx, ny} });
				}
			}
			else {//이전 방향과 다른 방향이면
				if (visited[nx][ny][i]) {
					//방문했었는데 최소거울 갱신이 가능하면 갱신하고 큐에다 넣기
					if (D[nx][ny][i] > D[x][y][dir] + 1) {
						D[nx][ny][i] = D[x][y][dir] + 1;//갱신
						Q.push({ i, {nx, ny} });
					}
				}
				else {
					D[nx][ny][i] = D[x][y][dir] + 1;//거울 설치
					visited[nx][ny][i] = true;//방문 표시
					Q.push({ i, {nx, ny} });
				}
			}
		}
	}
}

void Input() {
	cin >> w >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> Matrix[i][j];
			if (Matrix[i][j] == 'C') {
				if (sx == 0 && sy == 0) {//시작좌표
					sx = i;
					sy = j;
				}
				else {                   //도착좌표
					ex = i;
					ey = j;
				}
			}
		}
	}
}

void Solution() {
	BFS(sx, sy);
	//답 출력
	int mn = INF;
	for (int i = 0; i < 4; i++) {
		if (!visited[ex][ey][i])continue;
		mn = min(mn, D[ex][ey][i]);
	}
	cout << mn - 1;//처음에 + 1되니 -1한게 답
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solve();

	return 0;
}