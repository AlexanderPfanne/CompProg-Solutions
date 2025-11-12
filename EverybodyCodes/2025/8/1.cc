#include "../utils.cc"

void solve() {
    const int NAILS = 32;

    vector<ll> inp;
    getInp([&](auto& cin, int){
        int x; char c;
        do {
            cin >> x;
            inp.pb(x);
        } while(cin >> c);
    });

    ll res = 0;
    F0R(i, SZ(inp) - 1)
        res += abs(inp[i] - inp[i + 1]) == NAILS/2;

    cout << res << endl;
}

