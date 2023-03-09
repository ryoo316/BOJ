#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 300001;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, int> v;

int n, m, k, x;
int D[Max] = {};

vector<int> V[Max];

void Dijkstra(int start) {
	priority_queue<v, vector<v>, greater<v>> Q;
	D[start] = 0;
	Q.push({ start, 0 });
	while (!Q.empty()) {
		int cur = Q.top().first;
		int dist = Q.top().second;
		Q.pop();
		if (dist > D[cur])continue;
		for (int i = 0; i < V[cur].size(); i++) {
			int nextv = V[cur][i];
			int nextdist = dist + 1;
			if (nextdist < D[nextv]) {
				D[nextv] = nextdist;
				Q.push({ nextv, D[nextv] });
			}
		}
	}
}

void Input() {
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		V[s].push_back(e);
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		D[i] = INF;
	}
	Dijkstra(x);
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;
		if (D[i] == k) {
			cout << i << "\n";
			flag = true;
		}
	}
	if (!flag)
		cout << -1;
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