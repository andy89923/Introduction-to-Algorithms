#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 0x3f3f3f3f
#define MAXS 150010
#define MAX 1010

int n;
int dp[MAXS];
lol m, k, ans;
lol a[MAX];

void init() {
	ans = INF;
	memset(dp, 0, sizeof(dp));
	memset(a, 0, sizeof(a));
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {	
		cin >> a[i];
	
		a[i] = a[i] * (n - i + 1);
	}
	
	lol sum = k * n;
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = MAXS - 1; j >= a[i]; j--) {
			if (dp[j - a[i]]) dp[j] = 1;
		}
	}
	
	for (int i = 0; i < MAXS; i++) {
		if (dp[i]) ans = min(ans, abs(sum + i - m));
	}
	
	cout << ans << '\n';
	
	return 0;
}