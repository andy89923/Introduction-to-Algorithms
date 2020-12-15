/*input
5 8
3 1
4 4
3 0
1 0
1 4
0 1
3 2
4 1
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int n, m;
int ans;
vector<int> all, lis;
vector<int> v[MAX], r[MAX];
int vis[MAX], cnt;

void init() {
	all.clear();
	lis.clear();
	for (int i = 0; i < MAX; i++) v[i].clear();
}

void dfs_stamp(int now) {
	vis[now] = 1;
	for (auto i : r[now]) if (!vis[i]) dfs_stamp(i);

	lis.push_back(now);
}

void dfs(int now) {
	vis[now] = 1;
	for (auto i : v[now]) if (!vis[i]) dfs(i);

	cnt ++;
}

void solve() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) if (!vis[i]) dfs_stamp(i);

	memset(vis, 0, sizeof(vis));
	for (int i = n - 1; i >= 0; i--) if (!vis[lis[i]]) {
		cnt = 0;
		dfs(lis[i]);

		all.push_back(cnt);
	}

	if (all.size() < 2) { 
		ans = 0;
		return; 
	}
	sort(all.begin(), all.end());

	ans = all[all.size() - 2];
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		r[y].push_back(x);
	}
	solve();

	cout << ans << '\n';
	return 0;
}