#include "../utils.cc"

typedef pair<ll, ll> ll2;

ll area(ll2 a, ll2 b) {
    ll2 c = a - b;
    return (abs(c.fi) + 1) * (abs(c.se) + 1);
}

void solve() {
    vector<ll2> inp;
    getInp([&](auto& in, int) {
        ll a, b; char _;
        in >> a >> _ >> b;
        inp.eb(a, b);
    });

    ll res = 0;
    F0R(i, SZ(inp)) FOR(j, i + 1, SZ(inp))
        ckmax(res, area(inp[i], inp[j]));
    cout << res << endl;
}

