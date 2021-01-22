/*input
8 4 10
3 0 1 1
6 0 1 6
1 0 5 1
1 0 0 1
1 1 0 1
2 0 0 1
1 0 1 1
1 0 1 3
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXT 1002
#define MAX 102

struct sta {
	int x, y, c;
};

int n, m, t;
int a[MAX][MAX];
int k[MAX][MAX][MAXT];
queue<sta> q;

const int dx[5] = {-1, 0, 1, 0, 0};
const int dy[5] = {0, 1, 0, -1, 0};

struct mos {
	int x, y, d;

	void build() {
		int nx = x, ny = y, nd = d;

		k[x][y][0] = 1;
		for (int i = 1; i <= t; ++i) {
			nx = x + dx[nd - 4];
			ny = y + dy[nd - 4];

			if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 0) {
				nd += 1;
				if (nd == 8) nd = 4;
			} else {
				x = nx;
				y = ny;
			}
			k[x][y][i] = 1;
		}
	}
};

vector<mos> mts;
int ans;
int vis[MAX][MAX][MAXT];

void init() {
	ans = -1;
	mts.clear();
	while (q.size()) q.pop();
	memset(k, 0, sizeof(k));
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));
}

void solve() {
	for (auto i : mts) i.build();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			vis[i][j][0] = 0;
		}
	}
	int cnt = 0;
	while (q.size()) {
		cnt ++;
		sta now = q.front(); q.pop();				
		
		if (now.c >= t) return;

		for (int i = 0; i < 5; ++i) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

			if (a[nx][ny] == 0) continue;
			if (k[nx][ny][now.c]) continue;
			if (k[nx][ny][now.c + 1]) continue;
			if (vis[nx][ny][now.c + 1]) continue;
			
			vis[nx][ny][now.c + 1] = 1;

			if (a[nx][ny] == 3) {
				ans = now.c + 1;
				return;
			}
			if (now.c + 1 < t) 
				q.push((sta){nx, ny, now.c + 1});
		}
	}
}

bool check() {
	queue<pair<int, int> > qs;
	while (qs.size()) qs.pop();

	qs.push(make_pair(q.front().x, q.front().y));
	
	pair<int, int> now;
	while (qs.size()) {;
		now = qs.front(); qs.pop();

		vis[now.first][now.second][0] = 1;

		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (a[nx][ny] == 0) continue;
			if (vis[nx][ny][0]) continue;
			vis[nx][ny][0] = 1;

			if (a[nx][ny] == 3) return true;

			qs.push(make_pair(nx, ny));
		}
	}
	return false;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n >> m >> t;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];

			if (a[i][j] == 2) q.push((sta){i, j, 0});
			if (4 <= a[i][j])
				mts.push_back((mos){i, j, a[i][j]});
		}
	}
	if (check()) solve();

	cout << ans << '\n';
	return 0;
}