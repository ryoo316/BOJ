#include<iostream>
#include<queue>
constexpr auto Max = 51;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, pair<int, int>> v;

int n;
char Matrix[Max][Max] = {};
int D[Max][Max] = {};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Dijkstra() {
	priority_queue<v, vector<v>, greater<v>> Q;
	D[1][1] = 0;
	Q.push({ 0, {1, 1} });
	while (!Q.empty()) {
		int cnt = Q.top().first;
		int x = Q.top().second.first;
		int y = Q.top().second.second;
		Q.pop();
		if (cnt > D[x][y])continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n)continue;
			int nextcnt = cnt;
			if (Matrix[nx][ny] == '0')
				nextcnt++;
			if (nextcnt < D[nx][ny]) {
				D[nx][ny] = nextcnt;
				Q.push({ D[nx][ny], {nx, ny} });
			}
		}
	}
}

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Matrix[i][j];
		}
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] = INF;
		}
	}
	Dijkstra();
	cout << D[n][n];
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