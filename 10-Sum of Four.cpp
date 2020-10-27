/*input
10 4
2 1 1 1 1 1 1 1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define F first
#define S second
#define MAX 2510

int n;
vector<pair<lol, pair<int, int> > > v;
lol s, a[MAX];

void init() {
	v.clear();
	memset(a, 0, sizeof(a));
}

void preOutput(int& p1, int& p2, int& p3, int& p4) {
	int tmp[4];
	tmp[0] = p1; 
	tmp[1] = p2; 
	tmp[2] = p3; 
	tmp[3] = p4; 
	sort(tmp, tmp + 4);
	p1 = tmp[0] - 1; 
	p2 = tmp[1] - 1; 
	p3 = tmp[2] - 1; 
	p4 = tmp[3] - 1;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			v.push_back(make_pair(a[i] + a[j], make_pair(i, j)));
		}
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			lol fid = s - (a[i] + a[j]);
			auto poi = lower_bound(v.begin(), v.end(), make_pair(fid, make_pair(0, 0)));

			while (poi < v.end() && (*poi).F == fid) {
				int p1 = (*poi).S.F;
				int p2 = (*poi).S.S;

				poi++;
				if (p1 == i || p1 == j) continue;
				if (p2 == i || p2 == j) continue;

				// cout << i << ' ' << j << ' ' << p1 << ' ' << p2 << '\n';
				preOutput(i, j, p1, p2);

				cout << i << ' ' << j << ' ' << p1 << ' ' << p2 << '\n';
				return 0;
			}

		}
	}
	cout << -1 << '\n';

	return 0;
}