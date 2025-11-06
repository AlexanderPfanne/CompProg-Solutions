#include "../utils.cc"

void solve() {
    vector<ll> inp;
    ll mn = 1e9, cnt = 0, total = 0;
    
    getInp([&](auto& cin, int) {
        ll x; cin >> x;
        ++cnt;
        ckmin(mn, x);
        total += x;
    });

    cout << total - cnt*mn << endl;
}

