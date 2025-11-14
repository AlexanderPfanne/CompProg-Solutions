#include "../utils.cc"

void solve() {
    vector<string> inp;
    getInp([&](auto& in, int) {
        int x; char c; in >> x >> c;
        string s; in >> s;
        inp.pb(s);
    });

    sort(ALL(inp));
    do {
        bool ok = true;
        F0R(i, SZ(inp[0])) ok &= inp[0][i] == inp[1][i] || inp[0][i] == inp[2][i];
        if(!ok) continue;
        
        ll res = 1;
        FOR(i, 1, SZ(inp)) {
            ll match = 0;
            F0R(j, SZ(inp[0])) match += inp[0][j] == inp[i][j];
            res *= match;
        }
        cout << res << endl;
    } while (next_permutation(ALL(inp)));

}

