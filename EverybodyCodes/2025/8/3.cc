#include "../utils.cc"

#undef endl
void solve() {
    const int NAILS = 256;

    vector<ll> inp;
    getInp([&](auto& cin, int){
        int x; char c;
        do {
            cin >> x;
            inp.pb(x);
        } while(cin >> c);
    });

    ll res = 0;
    FOR(i, 1, NAILS + 1) FOR(k, 1, i) {
        ll amt = 0;
        F0R(j, SZ(inp) - 1) {
            int mn = min(inp[j], inp[j + 1]);
            int mx = max(inp[j], inp[j + 1]);
            amt += (k < mn && mn < i && i < mx) ||
                   (mn < k && k < mx && mx < i) ||
                   (mn == k && mx == i);
        }
        ckmax(res, amt);
    }
    cout << res << endl;
}

