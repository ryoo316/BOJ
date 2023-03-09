#include<iostream>
#include<algorithm>
constexpr auto Max = 201;
constexpr auto INF = 1e9 + 7;
using namespace std;

int n, m, k;
int adj[Max][Max] = {};
int dist[Max][Max] = {};
int citynum[Max] = {};

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adj[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s][e] = min(adj[s][e], c);
	}
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> citynum[i];
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}
	//플로이드-와샬 알고리즘
	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
			}
		}
	}
	int min_sum = INF;//최소 왕복거리
	int maxend[Max] = {};
	for (int e = 1; e <= n; e++) {//왕복할 도시
		for (int i = 1; i <= k; i++) {
			int s = citynum[i];//시작 도시
			int sum = 0;
			sum += dist[s][e];
			sum += dist[e][s];
			maxend[e] = max(maxend[e], sum);
		}
		min_sum = min(min_sum, maxend[e]);
	}
	for (int i = 1; i <= n; i++) {
		if (min_sum == maxend[i])
			cout << i << " ";
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