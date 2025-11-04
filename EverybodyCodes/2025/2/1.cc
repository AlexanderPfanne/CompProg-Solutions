#include "../utils.cc"

typedef pair<ll, ll> ll2;

ll2 mul(ll2& a, ll2& b) {
    return mp(a.fi * b.fi - a.se * b.se, a.fi * b.se + a.se * b.fi);
}

void solve() {
    ll2 a = mp(25, 9),
            curr = mp(0, 0);
    F0R(_, 3) {
        curr = mul(curr, curr);
        curr /= 10;
        curr += a;
    }

    cout << '[' << curr.fi << ',' << curr.se << ']' << endl;
}

