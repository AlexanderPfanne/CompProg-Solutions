#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<vector<ll>> inp;
    getInp([&](auto& in, int) {
        if(isdigit(in.peek())) {
            inp.eb();
            for(ll k; in >> k;) inp.back().pb(k);
        } else {
            char op;
            for(int i = 0; in >> op; ++i) {
                ll total = op == '*';
                F0R(j, SZ(inp)) {
                    if(op == '*') total *= inp[j][i];
                    else if(op == '+') total += inp[j][i];
                    else assert(false);
                }
                res += total;
            }
        }
    });
    cout << res << endl;
}

