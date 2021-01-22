/*input
5 8 1 3 4
3 1 3
1 0 2
4 3 7
0 2 1
4 2 1
1 4 5
2 3 4
0 4 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long lol;
#define F first
#define S second
#define INF 1000000000000000
#define MAX 10005

lol n, m, ans;
lol dis[MAX][3], vis[MAX];
pii u[3];
priority_queue<pii, vector<pii>, greater<pii>  > pr;
vector<pii> v[MAX];

void init() {
	ans = INF;
	memset(vis,   0, sizeof(vis));
	for (lol i = 0; i < MAX; i++) {
		v[i].clear();
		dis[i][0] = dis[i][1] = dis[i][2] = INF;
	}
}

void dijkstra(lol st, lol t) {
	memset(vis, 0, sizeof(vis));
	while (pr.size()) pr.pop();

	pr.push(make_pair(0, st));
	while (pr.size()) {
		auto now = pr.top(); pr.pop();

		if (vis[now.S]) continue;
		vis[now.S] = 1;
		dis[now.S][t] = now.F;

		for (auto i : v[now.S]) if (!vis[i.F]) {
			pr.push(make_pair(now.F + i.S, i.F));
		}
	}
}

void solve() {
	for (lol i = 0; i < 3; i++) {
		u[i].S = i;
		dijkstra(u[i].F, u[i].S);
	}

	do {
		lol dis1 = dis[u[1].F][u[0].S];
		lol dis2 = dis[u[2].F][u[1].S];
		lol dis3 = dis[u[0].F][u[2].S];

		ans = min(ans, dis1 + dis2 + dis3);
		// cout << u[0].F << ' ' << u[1].F << ' ' << u[2].F << ", now = " << dis1 + dis2 + dis3 << '\n';

	} while (next_permutation(u, u + 3));
}

int32_t main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n >> m >> u[0].F >> u[1].F >> u[2].F;
	for (lol i = 1; i <= m; i++) {
		lol x, y, c; cin >> x >> y >> c;
		v[x].push_back(make_pair(y, c));
	}
	solve();

	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}