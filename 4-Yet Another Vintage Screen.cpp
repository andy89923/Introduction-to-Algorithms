/*input
4
helloworldhelloworld
helloworldhelloworld
helloworldhelloworld
helloworldhelloworld
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> v;

bool test(int m) {
	int res = 1, sum = 0;
	for (auto i : v) {
		if (sum != 0 && sum + i > m) {
			res += 1;
			sum = 0;
		}
		sum = sum + i + 1;
	}
	return (res <= 24);
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	int n;
	int x = 0, y = 1000000, ans;

	v.clear();
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;

		int len = (int) s.length();
		x = max(x, len);

		v.push_back(len);
	}

	while (x < y) {
		int m = x + (y - x) / 2;

		if (test(m)) {
			y = m;
			ans = m;
		}
		else
			x = m + 1;
	}

	cout << ans << '\n';
	return 0;
}