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

    vector<vector<ll>> scores;
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

        scores.eb();
        scores.back().pb(res);
        F0R(i, SZ(mid)) {
            res = 0;
            if(small[i] != -1) res = res*10 + small[i];
            if(mid[i] != -1) res = res*10 + mid[i];
            if(big[i] != -1) res = res*10 + big[i];
            scores.back().pb(res);
        }
    }

    vi order(SZ(scores));
    iota(ALL(order), 0);
    sort(RALL(order), [&](int a, int b) {
        if(scores[a] != scores[b]) return scores[a] < scores[b];
        return a < b;
    });

    ll res = 0;
    F0R(i, SZ(scores)) res += (order[i] + 1)*(i + 1);
    cout << res;
}

