#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define MAX 5010

string s1, s2;
int dp[MAX][MAX];

void init() {
	memset(dp, 0, sizeof(dp));
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
	
	cin >> s1 >> s2;
	int n = (int) s1.length();
	int m = (int) s2.length();
	
	s1 = " " + s1;
	s2 = " " + s2;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[n][m] << '\n';
		

	return 0;
}