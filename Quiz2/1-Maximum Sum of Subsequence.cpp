#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define MAX 2000005

int n;
int a[MAX], dp[MAX];

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
	}
	
	cout << dp[n] << '\n';
	return 0;
}