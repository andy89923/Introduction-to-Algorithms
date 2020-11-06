/*input
7
abcdcba
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define INF 0x3f3f3f3f
#define MINCHAR 33
#define MAXCHAR 126
#define MAX 7005

int n, ans;
int tab_pre[MAX][150], tab_suf[MAX][150];
int mp[MAX][MAX];
char c[MAX];

void init() {
	ans = 1;
	memset(c, 0, sizeof(c));
	memset(mp, 0, sizeof(mp));
	memset(tab_pre, 0, sizeof(tab_pre));
	memset(tab_suf, INF, sizeof(tab_suf));
	for (int i = 1; i < MAX; i++) mp[i][i] = 1;
}

int cal(int x, int y) {
	if (y < x) return 0;
	if (mp[x][y]) return mp[x][y];

	// cout << "\nPorccess " << x << ' ' << y << '\n';

	int tmp = 1;
	for (int i = MINCHAR; i <= MAXCHAR; i++) { 
		int lef = tab_suf[x][i];
		int rig = tab_pre[y][i];

		if (rig < x || rig > y) continue; // rig out of x ~ y
		if (lef < x || lef > y) continue; // lef out of x ~ y
		if (lef + 1 >= rig) continue;

		// cout << "Char " << (char) i << ", " << lef << ' ' << rig << '\n';

		tmp = max(tmp, 2 + cal(lef + 2, rig - 2));
	}
	mp[x][y] = tmp;

	// cout << "Ans for (" << x << ", " << y << ") = " << tmp << "\n\n";

	return mp[x][y];
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = MINCHAR; j <= MAXCHAR; j++) {
			if (c[i] == j) 
				tab_pre[i][j] = i;
			else 
				tab_pre[i][j] = tab_pre[i - 1][j];
	}
	for (int i = n; i >= 1; i--)
		for (int j = MINCHAR; j <= MAXCHAR; j++) {
			if (c[i] == j) 
				tab_suf[i][j] = i;
			else 
				tab_suf[i][j] = tab_suf[i + 1][j];
			
	}
	ans = cal(1, n);

	cout << ans << '\n';

	return 0;
}