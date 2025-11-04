#include "../utils.cc"

typedef pair<ll, ll> ll2;

ll2 mul(ll2& a, ll2& b) {
    return mp(a.fi * b.fi - a.se * b.se, a.fi * b.se + a.se * b.fi);
}

bool engrave(ll2 pt) {
    ll2 curr = mp(0, 0);
    F0R(_, 100) {
        curr = mul(curr, curr);
        curr /= 100000;
        curr += pt;
        if(curr.fi < -1000000 || curr.fi > 1000000 ||
           curr.se < -1000000 || curr.se > 1000000) return false;
    }
    return true;
}

void solve() {
    ll2 a = mp(-79027,-15068);

    ll res = 0;
    F0R(i, 1001) F0R(j, 1001)
        res += engrave(a + mp(i, j));
    cout << res << endl;
}

