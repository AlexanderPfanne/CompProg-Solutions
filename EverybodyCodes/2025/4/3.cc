#include "../utils.cc"

void solve() {
    vector<pair<ll, ll>> inp;
    getInp([&](auto& cin, int) {
        int x, y; cin >> x;
        char c;
        if(cin >> c) cin >> y;
        else y = x;
        inp.eb(x, y);
    });

    double perRot = 100;
    F0R(i, SZ(inp) - 1) perRot *= (double)inp[i].se/inp[i + 1].fi;
    cout << (ll)perRot << endl;
}

