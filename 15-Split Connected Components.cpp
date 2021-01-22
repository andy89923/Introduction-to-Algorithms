/*input
4 5 8
0 0
0 1
2 3
3 1
1 0
-1 2
1 3
-1 2
0 1
2 0
-1 1
2 3
-1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define MAXN 5005
#define MAXQ 500005

multiset<pii> edges;
int p[MAXN], s[MAXN];
int n, m, q;
int ans[MAXQ];

int findset(int x) {
    return p[x] == x ? x : p[x] = findset(p[x]);
}

struct query {
    int p, x, y;
};

vector<query> qs;

void init() {
    qs.clear();
    edges.clear();
    for (int i = 0; i < MAXN; i++) {
        s[i] = 1;
        p[i] = i;
    }
    memset(ans, -1, sizeof(ans));
}

void uni(int x, int y) {
    x = findset(x);
    y = findset(y);

    if (x != y) {
        if (s[x] < s[y]) swap(x, y);

        p[y] = x;
        s[x] += s[y];
    }
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);
    init();

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;

        if (x > y) swap(x, y);
        edges.insert(make_pair(x, y));
    }
    for (int i = 1; i <= q; i++) {
        query now; now.p = i;

        cin >> now.x >> now.y;
        if (now.x >= 0) {
            if (now.x > now.y) swap(now.x, now.y);

            auto it = edges.find(make_pair(now.x, now.y));
            if (it != edges.end()) {
                edges.erase(it);
                qs.push_back(now);
            }
        } else 
            qs.push_back(now);
    }
    for (auto i : edges) uni(i.first, i.second);
    reverse(qs.begin(), qs.end());
    for (auto i : qs) {
        if (i.x != -1) {
            uni(i.x, i.y);
            continue;
        }
        int y = findset(i.y);
        ans[i.p] = s[y];
    }

    for (int i = 1; i <= q; i++) if (ans[i] != -1) {
        cout << ans[i] << '\n';
    }
    return 0;
}