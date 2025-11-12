#include "../utils.cc"

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
    FOR(i, 1, SZ(inp) - 1) {
        F0R(j, i - 1) {
            int mn1 = min(inp[i], inp[i + 1]);
            int mx1 = max(inp[i], inp[i + 1]);
            int mn2 = min(inp[j], inp[j + 1]);
            int mx2 = max(inp[j], inp[j + 1]);
            res += (mn1 < mn2 && mn2 < mx1 && mx1 < mx2) ||
                   (mn2 < mn1 && mn1 < mx2 && mx2 < mx1);

        }
    }
    cout << res << endl;
}

