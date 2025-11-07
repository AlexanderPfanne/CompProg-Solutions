#include "../utils.cc"

void solve() {
    vector<vector<ll>> inp;
    getInp([&](auto& cin, int) {
        char c; int a;
        cin >> a >> c;
        inp.eb();
        while(cin >> a) {
            inp.back().pb(a);
            cin >> c;
        }
    });

    ll mn = 1e18;
    ll mx = -1;
    for(vector<ll>& v : inp) {
        vi small, mid, big;
        small.pb(-1);
        mid.pb(v[0]);
        big.pb(-1);

        FOR(i, 1, SZ(v)) {
            bool placed = false;
            F0R(j, SZ(mid)) {
                if(v[i] < mid[j] && small[j] == -1) {
                    small[j] = v[i];
                    placed = true;
                    break;
                } else if(v[i] > mid[j] && big[j] == -1) {
                    big[j] = v[i];
                    placed = true;
                    break;
                }
            }
            if(!placed) {
                small.pb(-1);
                mid.pb(v[i]);
                big.pb(-1);
            }
        }

        ll res = 0;
        F0R(i, SZ(mid)) res = res*10 + mid[i];
        ckmin(mn, res);
        ckmax(mx, res);
    }
    cout << mx - mn;
}
