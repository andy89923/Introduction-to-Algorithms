/*input
5 10 10
5 4 4
2 8 6
4 3 5
7 2 7
6 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 505

int n, w, v;
lol dp[MAX][MAX], ans;

void init() {
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0ll;
	ans = 0ll;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n >> w >> v;
	for (int i = 1; i <= n; i++) {
		int now_wei, now_vol, now_pft;

		cin >> now_wei >> now_vol >> now_pft;

		if (now_wei > w) continue;
		if (now_vol > v) continue;

		for (int j = w; j >= now_wei; j--) {
			for (int k = v; k >= now_vol; k--) {
				if (dp[j - now_wei][k - now_vol] != -1) {
					dp[j][k] = max(dp[j][k], dp[j - now_wei][k - now_vol] + now_pft);
					ans = max(ans, dp[j][k]);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}