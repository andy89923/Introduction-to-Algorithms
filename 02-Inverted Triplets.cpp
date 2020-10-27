#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<lol, lol> pii;
#define F first
#define S second
#define MAX 100010

int n, a[MAX];
pii p[MAX  * 4];
vector<int> all;
lol ans = 0;

lol u1, u2;
int ql, qr;

void update(int x, int y, int now) {
	if (x == y) {
		p[now].F += u1;
		p[now].S += u2;

		return;
	}

	int m = x + (y - x) / 2;
	if (ql <= m) update(x, m, now * 2);
	if (m  < ql) update(m + 1, y, now * 2 + 1);

	p[now].F = p[now * 2].F + p[now * 2 + 1].F;
	p[now].S = p[now * 2].S + p[now * 2 + 1].S;
}

pii query(int x, int y, int now) {
	if (ql <= x && y <= qr) return p[now];

	int m = x + (y - x) / 2;
	pii lef = make_pair(0, 0), rig = make_pair(0, 0);

	if (ql <= m) lef = query(x, m, now * 2);
	if (m  < qr) rig = query(m + 1, y, now * 2 + 1);

	return make_pair(lef.F + rig.F, lef.S + rig.S);
}

void init() {
	all.clear();
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());

	for (int i = 1; i <= n; i++) {
		int x = (int)(lower_bound(all.begin(), all.end(), a[i]) - all.begin()) + 1;

		ql = x + 1; qr = n;
		pii now = query(1, n, 1);

		ans += now.S;

		u1 = 1; u2 = now.F;
		ql = x;

		update(1, n, 1);
	}

	cout << ans << '\n';
	return 0;
}