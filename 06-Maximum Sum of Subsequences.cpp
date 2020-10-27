/*input
10 10
8 8 1 1 10 1 3 10 9 1
1 5 9
0 5 8
1 5 9
0 1 5
1 0 4
0 2 6
0 3 3
1 3 6
1 0 5
1 4 7
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 500005

struct node {
    int nbs, nil, nir, bbs;

    void init() {
        nbs = bbs = 0;
        nil = nir = 0;
    }

    int ans() {
        // cout << nbs << ' ' << bbs << ' ' << nil << ' ' << nir << ' ' << '\n';
        return max(nbs, max(bbs, max(nil, nir)));
    }

    node operator + (const node& rhs) {
        node now; now.init();

        // include right bound and left bound
        now.bbs = max(bbs + rhs.nil, nir + rhs.bbs);

        // not include left & right bound
        now.nbs = max(nil + rhs.nbs, nbs + rhs.nir);

        // not include left
        now.nil = max(nil + rhs.nil, nbs + rhs.bbs);

        // not include right
        now.nir = max(bbs + rhs.nbs, nir + rhs.nir);

        return now;
    }
};

node p[MAX * 4];
int n, m, a[MAX];
int ql, qr;

void init() {
    memset(p, 0, sizeof(p));
    memset(a, 0, sizeof(a));
}

void build(int x, int y, int now) {
    if (x == y) {
        p[now].bbs = a[x];
        return;
    }
    int m = x + (y - x) / 2, ls = now * 2, rs = now * 2 + 1;
    
    build(x, m, now * 2);
    build(m + 1, y, now * 2 + 1);

    p[now] = p[now * 2] + p[now * 2 + 1];
    // cout << "Node " << now << '\n'; p[now].ans(); cout << '\n';
}

void update(int x, int y, int now) {
    if (x == y) {
        p[now].bbs = qr;
        return;
    }
    int m = x + (y - x) / 2;

    if (ql <= m) update(x, m, now * 2);
    if (m  < ql) update(m + 1, y, now * 2 + 1);

    p[now] = p[now * 2] + p[now * 2 + 1]; 
}

node query(int x, int y, int now) {
    if (ql <= x && y <= qr) return p[now];

    node ll, rr; ll.init(); rr.init();
    int m = x + (y - x) / 2;

    if (ql <= m) ll = query(x, m, now * 2);
    if (m  < qr) rr = query(m + 1, y, now * 2 + 1);

    return ll + rr;
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);

    for (int i = 1; i <= m; i++) {
        int ope; cin >> ope >> ql >> qr;
        ql += 1;

        if (ope == 0) update(1, n, 1);
        else {
            qr += 1;
            node now = query(1, n, 1);

            cout << now.ans() << '\n';
        }
    }
    return 0;
}