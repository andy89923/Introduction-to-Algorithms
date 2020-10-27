/*input
6
2 5 5 3 10 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lol;

int n;
lol ans;
priority_queue<lol> pr;

void init() {
    while (pr.size()) pr.pop();
    ans = 0;
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        lol x; cin >> x;
        pr.push(x);
    }

    while (pr.size() > 1) {
        lol a = pr.top(); pr.pop();
        lol b = pr.top(); pr.pop();

        if (a == b) {
            pr.push(0);
            continue;
        }
        if (b == 0) {
            ans += a;
            continue;
        }
        pr.push(0);
        pr.push(a - b);

        ans += a - b;
    } 
    cout << ans << '\n';
    return 0;
}