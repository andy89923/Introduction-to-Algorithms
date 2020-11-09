/*input
10 2
-4 8 -3 7 -6 -9 -2 4 -2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 10000000000000000
#define MAX 1000010

int n, k;
lol a[MAX], ans;

void init() {
	ans = 0;
	memset(a, 0, sizeof(a));
}

bool test(lol l) {
	int cnt = 0;
	lol bac = a[1] - 1;

	for (int i = 1; i <= n; i++) {
		if (bac < a[i]) {
			cnt += 1;
			bac = a[i] + l;
		}
	}
	return (cnt <= k);
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);

	lol x = 0ll, y = INF, m;
	while (x < y) {

		m = x + (y - x) / 2ll;
		if (test(m)) {
			ans = m;
			y = m;
		}
		else
			x = m + 1;
	}

	cout << ans << '\n';

	return 0;
}