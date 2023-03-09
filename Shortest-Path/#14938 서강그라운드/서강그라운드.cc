#include<iostream>
#include<algorithm>
constexpr auto Max = 101;
constexpr auto INF = 922222;
using namespace std;

int n, m, r;
int Item[Max] = {};
int adj[Max][Max] = {};
int dist[Max][Max] = {};

void Input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> Item[i];
	}
	for (int i = 0; i < r; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s][e] = c;
		adj[e][s] = c;
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
			}
		}
	}
	int maxitem = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)continue;
			if (dist[i][j] <= m) {
				cnt += Item[j];
			}
		}
		maxitem = max(maxitem, cnt);
	}
	cout << maxitem;
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