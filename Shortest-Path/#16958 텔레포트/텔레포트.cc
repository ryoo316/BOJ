#include<iostream>
#include<queue>
#include<vector>
constexpr auto Max = 1001;
constexpr auto INF = 1e9 + 7;
using namespace std;

typedef pair<int, pair<int, int>> v;

int n, t;
int city[Max][4] = {};
int dist[Max][Max] = {};

vector<int> ans;

void Input() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		city[i][0] = s;
		city[i][1] = x;
		city[i][2] = y;
	}
}

void Solution() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (i == j) continue;
			int teleportdist = INF;
			int d = abs(city[i][1] - city[j][1])
				  + abs(city[i][2] - city[j][2]);
			if (city[i][0] + city[j][0] == 2)
				teleportdist = t;
			if (teleportdist == t && t < d)
				dist[i][j] = t;
			else
				dist[i][j] = d;
		}
	}
	for (int m = 1; m <= n; m++) {			//거쳐가는 도시
		for (int s = 1; s <= n; s++) {		//시작도시
			for (int e = 1; e <= n; e++) {	//도착도시
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		ans.push_back(dist[s][e]);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
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