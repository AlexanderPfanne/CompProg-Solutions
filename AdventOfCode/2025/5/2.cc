#include "../utils.cc"

void solve() {
    vector<pair<ll, ll>> ps;
    
    getInp([&](auto& in, int) {
        static bool range = true;
        ll l, r; char c;
        if(in >> l && range) {
            in >> c >> r;
            ps.eb(l, r);
        } else {
            range = false;
        }
    });

    sort(ALL(ps));

    ll res = 0;
    auto [currL, currR] = ps[0];
    for(auto [l, r] : ps) {
        if(l <= currR) {
            ckmax(currR, r);
        } else {
            res += currR - currL + 1;
            currL = l;
            currR = r;
        }

    }
    res += currR - currL + 1;

    cout << res << endl;
}

