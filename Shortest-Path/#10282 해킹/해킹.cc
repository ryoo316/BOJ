#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
constexpr auto Max = 10001;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, int> v;

int n = 1, m, sv, cnt = 0, maxtime = 0;
int D[Max] = {};

vector<pair<int, int>> V[Max];

void Dijkstra(int start) {
	priority_queue<v, vector<v>, greater<v>> Q;
	D[start] = 0;
	Q.push({ 0, start });
	while (!Q.empty()) {
		int dist = Q.top().first;
		int cur = Q.top().second;
		Q.pop();
		if (dist > D[cur])continue;
		for (int i = 0; i < V[cur].size(); i++) {
			int nextv = V[cur][i].first;
			int nextdist = dist + V[cur][i].second;
			if (nextdist < D[nextv]) {
				D[nextv] = nextdist;
				Q.push({ D[nextv], nextv });
			}
		}
	}
}

void Init() {
	for (int i = 1; i <= n; i++) {
		V[i].clear();
	}
	cnt = 0;
	maxtime = 0;
}

void Input() {
	cin >> n >> m >> sv;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> e >> s >> c;
		V[s].push_back({ e, c });
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		D[i] = INF;
	}
	Dijkstra(sv);
	for (int i = 1; i <= n; i++) {
		if (D[i] != INF) {
			cnt++;
			maxtime = max(maxtime, D[i]);
		}
	}
	cout << cnt << " " << maxtime << "\n";
}

void Solve() {
	Init();
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--)
		Solve();

	return 0;
}