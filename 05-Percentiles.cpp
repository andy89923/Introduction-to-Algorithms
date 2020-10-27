/*input
10 50
2 0 6 0 4 0 5 0 7 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define F first
#define S second

map<lol, lol> mp;
int sml, cnt, k;
lol ans, n;

void init() {
	sml = 0;
	cnt = 0;
	mp.clear();
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	int t;
	cin >> t >> k;
	while (t--) {

		cin >> n;
		if (n == 0ll) {
			
			cout << ans << '\n';

		} else {
			cnt += 1;
			mp[n] = mp[n] + 1;
			
			int num = (cnt * k + 99) / 100;

			if (cnt == 1) {
				ans = n;
				sml = 1;
				continue;
			}

			if (n <= ans) sml += 1;

			while (sml - mp[ans] >= num) {
				auto it = mp.lower_bound(ans);
				if (it == mp.begin()) break;
				it--; 
				
				sml = sml - mp[ans];
				ans = it -> first;
			}
			while (sml < num) {
				auto it = mp.lower_bound(ans);
				it++;
				
				ans = it -> first;
				sml = sml + it -> second;
			}
		}
	}
	return 0;
}