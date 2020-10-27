/*input
13
1
2
3
4
5
6
7
8
9
10
100
1000000000
2147483647
*/
#include <bits/stdc++.h>
using namespace std;

double f(double x) {
	return x * exp(x);
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		double tar; cin >> tar;

		double x = 0.0, y = 10000000000;
		while (y - x > 1e-6) {
			double m = x + (y - x) / 2.0;
			double ret = f(m);

			if (tar < ret) y = m;
			else
				x = m;
		}
		cout << fixed << setprecision(6) << x << '\n';
	}
	return 0;
}