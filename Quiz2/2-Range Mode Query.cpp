/*input
6 3
5 4 4 2 5 2
2 3
3 5
0 2
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 500010

int a[MAX];
int n, m;

map<int, int> mp;

int query(int x, int y) {
	mp.clear();

	int now_max = 0, now_ans = 0;
	for (int i = x; i <= y; i++) {
		int tmp = (mp[a[i]] = 1 + mp[a[i]]);

		if (tmp > now_max) {
			now_max = tmp;
			now_ans = a[i];
		}
		if (tmp == now_max) {
			now_ans = min(now_ans, a[i]);
		}
	}
	return now_ans;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;

		cout << query(x + 1, y) << '\n';
	}
	return 0;
}