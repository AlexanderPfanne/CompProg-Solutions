#include "../utils.cc"

void solve() {
    vector<ll> inp;
    getInp([&](auto& cin, int) {
        ll x; cin >> x;
        inp.pb(x);
    });

    ll mn = 1e9;
    for(int x : inp) {
        ll curr = 0;
        for(int y : inp) curr += abs(y - x);
        ckmin(mn, curr);
    }
    cout << mn << endl;
}

