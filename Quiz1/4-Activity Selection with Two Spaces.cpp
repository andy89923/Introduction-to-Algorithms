#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 500010

struct act {
	int s, t;
	
	bool operator < (const act& rhs) const {
		if (t != rhs.t) return t < rhs.t;
		return s < rhs.s;
	}
} a[MAX];

int n;
int ans;

void init() {
	ans = 0;
	memset(a, 0, sizeof(a));
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].t;
	sort(a + 1, a + 1 + n);
	
	int bac1 = 0, bac2 = 0;
	for (int i = 1; i <= n; i++) {
		
		if (bac1 <= a[i].s && bac2 <= a[i].s) {
			if (a[i].s - bac1 <= a[i].s - bac2) {
				bac1 = a[i].t;
			} else {
				bac2 = a[i].t;
			}
			ans += 1;
			continue;
		}
		
		if (bac1 <= a[i].s) {
			ans += 1;
			bac1 = a[i].t;
			continue;
		}
		if (bac2 <= a[i].s) {
			ans += 1;
			bac2 = a[i].t;
			continue;
		}
	}
	cout << ans << '\n';

	return 0;
}