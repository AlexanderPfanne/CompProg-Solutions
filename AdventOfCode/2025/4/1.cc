#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    ll res = 0;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] == '@') {
        int amt = 0;
        FOR(dr, -1, 2) FOR(dc, -1, 2) 
            TRY({ amt += ss.at(r + dr).at(c + dc) == '@'; });
        res += amt <= 4;
    }
    cout << res << endl;
}

