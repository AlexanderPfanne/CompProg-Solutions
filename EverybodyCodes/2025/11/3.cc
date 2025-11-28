#include "../utils.cc"

void solve() {
    vector<ll> inp;
    getInp([&](auto& in, int) {
        ll i; in >> i; inp.pb(i);
    });

    // Already in Round 2
    F0R(i, SZ(inp) - 1) assert(inp[i] <= inp[i + 1]);

    ll res = 0;
    ll mean = accumulate(ALL(inp), 0ll) / SZ(inp);
    F0R(i, SZ(inp)) if(inp[i] < mean) res += mean - inp[i];
    cout << res << endl;
}
