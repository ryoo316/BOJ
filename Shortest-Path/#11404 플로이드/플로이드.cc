#include<iostream>
#include<algorithm>
constexpr auto Max = 101;
constexpr auto INF = 214748647;
using namespace std;

int n, m;

int adj[Max][Max] = {};
int dist[Max][Max] = {};

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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		if (adj[s][e] != 0 && adj[s][e] < c)
			continue;
		adj[s][e] = c;
	}
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