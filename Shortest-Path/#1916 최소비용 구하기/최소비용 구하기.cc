#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 1001;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, int> v;

int n, m;
int startv, endv;

int d[Max] = {};

vector<pair<int, int>> V[Max];

void Dijkstra(int start) {
	priority_queue<v, vector<v>, greater<v>> Q;
	Q.push({ start, 0 });
	d[start] = 0;
	while (!Q.empty()) {
		int cur = Q.top().first;
		int cnt = Q.top().second;
		Q.pop();
		if (cnt > d[cur])continue;
		for (int i = 0; i < V[cur].size(); i++) {
			int nextv = V[cur][i].first;
			int nextdist = cnt + V[cur][i].second;
			if (nextdist < d[nextv]) {
				d[nextv] = nextdist;
				Q.push({ nextv, d[nextv] });
			}
		}
	}
}

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		V[s].push_back({ e, c });
	}
	cin >> startv >> endv;
}

void Solution() {
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	Dijkstra(startv);
	cout << d[endv];
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