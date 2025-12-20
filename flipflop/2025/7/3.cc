#include "../utils.cc"

ll getAmt(vi& v) {
    static map<vi, ll> dp;
    if(dp.count(v)) return dp[v];

    ll res = 0;
    F0R(i, SZ(v)) if(v[i]) {
        --v[i];
        res += getAmt(v);
        ++v[i];
    }
    return dp[v] = res ? res : 1;
}

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        int r, c; in >> r >> c;
        vi v(r, c - 1);
        res += getAmt(v);
    });
    cout << res << endl;
}

