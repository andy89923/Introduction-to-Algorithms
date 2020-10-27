/*input
10 10
4 4 3 2 6 2 8 1 6 10
1 1 0
0 1 6
0 3 3
1 2 3
0 3 8
0 8 5
1 1 8
0 2 9
0 8 1
1 9 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 500010

lol a[MAX], p[MAX * 4];
int n;

void build(int x, int y, int now) {
	if (x == y) {
		p[now] = a[x];
		return;
	}
	int m = x + (y - x) / 2;

	build(x, m, now * 2);
	build(m + 1, y, now * 2 + 1);

	p[now] = p[now * 2] + p[now * 2 + 1];
}

int ql, qr;

lol query(int x, int y, int now) {
	if (ql <= x && y <= qr) return p[now];

	lol ll = 0, rr = 0;
	int m = x + (y - x) / 2;
	if (ql <= m) ll = query(x, m, now * 2);
	if (m  < qr) rr = query(m + 1, y, now * 2 + 1);

	return ll + rr;
}

lol modi;

void update(int x, int y, int now) {
	if (x == y) {
		p[now] = modi;
		return;
	}

	int m = x + (y - x) / 2;

	if (ql <= m) update(x, m, now * 2);
	if (m  < ql) update(m + 1, y, now * 2 + 1);

	p[now] = p[now * 2] + p[now * 2 + 1];
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	int t, ope;

	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, n, 1);

	while (t--) {
		cin >> ope >> ql >> qr;

		if (ope == 0) { // update
			ql += 1;
			modi = qr;
			update(1, n, 1);
		}
		if (ope == 1) { // query
			ql++; qr++;
			
			if (ql > qr) {
				swap(ql, qr);
				ql += 1; qr -= 1;
				cout << p[1] - query(1, n, 1) << '\n';
			}
			else
				cout << query(1, n, 1) << '\n';
		}
	}
	return 0;
}