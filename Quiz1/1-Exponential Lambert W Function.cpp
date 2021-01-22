#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6

double x, y, b, tar;
double lef, rig, m, p;

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	
	int t; cin >> t;
	while (t--) {
		cin >> y >> b;
		
		tar = y * log(b);
		
		lef = 0.0;
		rig = INT_MAX;
		
		while (rig - lef > eps) {
			m = lef + (rig - lef) / 2.0;
			p = m * log(m);
			
			if (p < tar) lef = m;
			else rig = m;
		}
		cout << fixed << setprecision(7) << rig << '\n';
	}	
	return 0;
}