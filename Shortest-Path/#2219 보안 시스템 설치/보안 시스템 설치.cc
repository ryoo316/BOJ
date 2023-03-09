#include<iostream>
#include<algorithm>
constexpr auto Max = 201;
constexpr auto INF = 1e9 + 7;
using namespace std;

int n, m;
int dist[Max][Max] = {};

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		dist[s][e] = min(dist[s][e], c);
		dist[e][s] = min(dist[e][s], c);
	}
}

void Solution() {
	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
			}
		}
	}
	int ans = 0;
	int min_sum = INF;
	for (int i = n; i >= 1; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)break;
			cnt += dist[i][j];
		}
		if (min_sum > cnt) {
			min_sum = cnt;
			ans = i;
		}
	}
	cout << ans << "\n";
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