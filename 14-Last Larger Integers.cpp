/*input
5
4 2 1 3 5
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

stack<int> s;

void init() {
    while (s.size()) s.pop();
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        while (s.size() && s.top() <= x) s.pop();

        if (s.empty()) 
            cout << -1 << ' ';
        else
            cout << s.top() << ' ';

        s.push(x);
    }
    cout << '\n';

    return 0;
}