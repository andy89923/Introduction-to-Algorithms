#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define MAX 20010

vector<int> v[MAX], r[MAX];
int n, m;
int vis[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		v[i].clear();
		r[i].clear();
	}
}

vector<int> stp;

void dfs(int now) {
	if (vis[now]) return;
	
	vis[now] = 1;
	for (auto i : v[now]) dfs(i);
}


void dfs_stamp(int now) {
	if (vis[now]) return;
	
	vis[now] = 1;
	for (auto i : r[now]) dfs_stamp(i);
	stp.push_back(now);
}

bool solve() {
	stp.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) if (!vis[i]) {
		dfs_stamp(i);
	}
	memset(vis, 0, sizeof(vis));
	
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) if (!vis[i]) {
		if (cnt == 1) return false;
		cnt += 1;
		dfs(i);
	}
	return true;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		init();
		
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			v[x].push_back(y);
			r[y].push_back(x);
		}
		cout << (solve() ? 1 : 0) << '\n'; 
	}

	return 0;
}