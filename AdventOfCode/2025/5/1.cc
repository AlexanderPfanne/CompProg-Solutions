#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<pair<ll, ll>> ps;

    getInp([&](auto& in, int i) {
        static bool range = true;
        ll l, r; char c;
        if(cin >> l) {
            if(range) {
                in >> c >> r;
                ps.eb(l, r);
            } else {
                for(auto [a, b] : ps) {
                    if(l >= a && l <= b) {
                        ++res;
                        break;
                    }
                }
            }
        } else {
            assert(range);
            range = false;
        }
    });
    cout << res << endl;
}

