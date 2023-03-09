#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 50001;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, int > v;

int n, m;
int D[Max] = {};

vector<pair<int, int>> V[Max];

void Dijkstra() {
	priority_queue<v, vector<v>, greater<v>> Q;
	D[1] = 0;
	Q.push({ 1, 0 });
	while (!Q.empty()) {
		int cur = Q.top().first;
		int dist = Q.top().second;
		Q.pop();
		if (dist > D[cur])continue;
		for (int i = 0; i < V[cur].size(); i++) {
			int nextv = V[cur][i].first;
			int nextdist = dist + V[cur][i].second;
			if (nextdist < D[nextv]) {
				D[nextv] = nextdist;
				Q.push({ nextv, D[nextv] });
			}
		}
	}
}

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		V[s].push_back({ e,c });
		V[e].push_back({ s,c });
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		D[i] = INF;
	}
	Dijkstra();
	cout << D[n];
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