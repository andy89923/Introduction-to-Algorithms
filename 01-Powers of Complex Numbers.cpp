#include <bits/stdc++.h>
using namespace std;
typedef long long lol;
#define mod 1000000007

struct cpx {
    
    lol rel, img;

    cpx(lol rel = 0, lol img = 0) {
        this -> rel = rel;
        this -> img = img;
    }

    cpx operator* (const cpx& rhs) const {
        cpx now;

        now.rel = (rel * rhs.rel) % mod - (img * rhs.img) % mod;
        now.img = (rel * rhs.img) % mod + (img * rhs.rel) % mod;

        now.rel = (now.rel + mod) % mod;
        now.img = (now.img + mod) % mod;

        return now;
    }
};

cpx complex_power(cpx now, lol n) {
    cpx ret(1, 0);
    if (n == 0) return ret;

    ret = complex_power(now, n / 2);
    ret = ret * ret;

    if (n % 2) ret = ret * now;

    return ret;
}

int main() {
    cin.tie(0), cout.sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        cpx now; 
        lol n;

        cin >> now.rel >> now.img >> n;

        now.rel %= mod;
        now.img %= mod;

        now = complex_power(now, n);

        cout << now.rel << ' ' << now.img << '\n';
    }
    return 0;
}