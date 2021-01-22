#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define MAX 505

int a[MAX][MAX];
int n;

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			
			if (i == j) {
				a[i][j] = 0; continue;
			}
			if (a[i][j]) continue;
			a[i][j] = INF;
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);	
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {	
			if (a[i][j] == INF) 
				cout << -1 << ' ';
			else
				cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}