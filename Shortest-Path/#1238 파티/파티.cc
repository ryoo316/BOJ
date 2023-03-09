#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 1001;
constexpr auto INF = 2147483647;
using namespace std;

typedef pair<int, int> v;

int n, m, x, maxtime = -123;

int d1[Max] = {};
int d2[Max] = {};

vector<pair<int, int>> V[Max];
vector<pair<int, int>> V_reverse[Max];

void Dijkstra_1(int startv) {
	priority_queue<v, vector<v>, greater<v>> Q;
	d1[startv] = 0;
	Q.push({ startv, 0 });
	while (!Q.empty()) {
		int cur = Q.top().first;
		int dist = Q.top().second;
		Q.pop();
		if (dist > d1[cur])continue;
		for (int i = 0; i < V_reverse[cur].size(); i++) {
			int nextv = V_reverse[cur][i].first;
			int nextdist = dist + V_reverse[cur][i].second;
			if (nextdist < d1[nextv]) {
				d1[nextv] = nextdist;
				Q.push({ nextv, d1[nextv] });
			}
		}
	}
}


void Dijkstra_2(int start) {
	priority_queue<v, vector<v>, greater<v>> Q;
	d2[start] = 0;
	Q.push({ start, 0 });
	while (!Q.empty()) {
		int cur = Q.top().first;
		int dist = Q.top().second;
		Q.pop();
		if (dist > d2[cur])continue;
		for (int i = 0; i < V[cur].size(); i++) {
			int nextv = V[cur][i].first;
			int nextdist = dist + V[cur][i].second;
			if (nextdist < d2[nextv]) {
				d2[nextv] = nextdist;
				Q.push({ nextv, d2[nextv] });
			}
		}
	}
}

void Input() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		V[s].push_back({ e, c });
		V_reverse[e].push_back({ s,c });
	}
}

void Solution() {
	for (int i = 1; i <= n; i++) {
		d1[i] = INF;
	}
	Dijkstra_1(x);
	for (int i = 1; i <= n; i++) {
		d2[i] = INF;
	}
	Dijkstra_2(x);
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;
		maxtime = max(d1[i] + d2[i], maxtime);
	}
	cout << maxtime;
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