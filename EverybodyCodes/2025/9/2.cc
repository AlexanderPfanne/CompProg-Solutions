#include "../utils.cc"

void solve() {
    vector<string> inp;
    getInp([&](auto& in, int) {
        int x; char c; in >> x >> c;
        string s; in >> s;
        inp.pb(s);
    });

    ll res = 0;
    F0R(c, SZ(inp)) {
        F0R(par1, SZ(inp)) FOR(par2, par1, SZ(inp)) if(c != par1 && c != par2) {
            ll match1 = 0, match2 = 0;
            F0R(i, SZ(inp[c])) {
                if(inp[c][i] != inp[par1][i] && inp[c][i] != inp[par2][i]) {
                    match1 = match2 = 0;
                    break;
                }
                match1 += inp[c][i] == inp[par1][i];
                match2 += inp[c][i] == inp[par2][i];
            }
            res += match1 * match2;
        }
    }
    cout << res << endl;

}

