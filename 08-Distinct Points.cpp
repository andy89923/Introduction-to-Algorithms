/*input
10
1 3 2
1 2 1
3 2 3
3 3 1
1 1 2
2 3 3
2 1 1
1 3 1
3 1 3
2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<lol, int> pii;
#define mod 1000000007
#define MAX 1000005

struct point {
	lol x, y, z;
	int p;

	bool operator < (const point& rhs) const {
		if (x != rhs.x) return x < rhs.x;
		if (y != rhs.y) return y < rhs.y;
		return z < rhs.z;
	}

	bool operator == (const point& rhs) const {
		if (x != rhs.x) return false;
		if (y != rhs.y) return false;
		return (z == rhs.z);
	}
} a[MAX];

lol f(lol a, lol b) {
	return a * 10000000ll + b;
}

int n;
int cnt[MAX][3], sum[MAX];
vector<pii> mxy, myz, mxz;

void init() {
	mxy.clear();
	myz.clear();
	mxz.clear();
	memset(a, 0, sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
}

void calculate(vector<pii>& v) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 < v.size() && v[i].first == v[j + 1].first) j++;

		for (int k = i; k <= j; k++) sum[v[k].second] += (j - i);
		i = j;
	}
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].p = i;

		cnt[a[i].x][0] += 1;
		cnt[a[i].y][1] += 1;
		cnt[a[i].z][2] += 1;	

		mxy.push_back(make_pair(f(a[i].x, a[i].y), i));
		myz.push_back(make_pair(f(a[i].y, a[i].z), i));
		mxz.push_back(make_pair(f(a[i].x, a[i].z), i));
	}

	sort(mxy.begin(), mxy.end()); calculate(mxy);
	sort(myz.begin(), myz.end()); calculate(myz);
	sort(mxz.begin(), mxz.end()); calculate(mxz);

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (a[i] == a[j + 1]) j++;

		int ans = n - 1;
		ans -= cnt[a[i].x][0] - 1;
		ans -= cnt[a[i].y][1] - 1;
		ans -= cnt[a[i].z][2] - 1;

		ans -= (j - i);

		for (int k = i; k <= j; k++) sum[a[k].p] += ans;
		i = j;
	}

	for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
	cout << '\n';

	return 0;
}
