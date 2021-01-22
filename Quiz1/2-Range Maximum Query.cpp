#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 2147483648
#define MAX 1000010

int a[MAX];
int p[MAX * 4];
int n, m;

void init() {
	memset(p, 0, sizeof(p));
}

void build(int x, int y, int now) {
	if (x == y) {
		p[now] = a[x];
		return;
	}
	
	int m = x + (y - x) / 2;
	build(x, m, now * 2);
	build(m + 1, y, now * 2 + 1);
	
	p[now] = max(p[now * 2], p[now * 2 + 1]);
}

int ql, qr;

int query(int x, int y, int now) {
	if (ql <= x && y <= qr) return p[now];
	
	int m = x + (y - x) / 2, ll = -INF, rr = -INF;
	if (ql <= m) ll = query(x, m, now * 2);
	if (m  < qr) rr = query(m + 1, y, now * 2 + 1);
	
	return max(ll, rr);
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, n, 1);
	
	
	while (m--) {
		cin >> ql >> qr;
		ql ++;
		qr ++;
		
		cout << query(1, n, 1) << '\n';
	}
	

	return 0;
}