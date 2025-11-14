#include "../utils.cc"

map<int, vector<int>> adj;
ii dfs(int i) {
    static set<int> seen;
    if(seen.count(i)) return mp(0, 0);
    seen.insert(i);
    ii res = mp(1, i + 1);
    for(int j : adj[i]) res += dfs(j);
    return res;
}

void solve() {
    vector<string> inp;
    getInp([&](auto& in, int) {
        int x; char c; in >> x >> c;
        string s; in >> s;
        inp.pb(s);
    });

    vector<int> inds(SZ(inp[0]));
    iota(ALL(inds), 0);

    F0R(c, SZ(inp)) {
        F0R(par1, SZ(inp)) FOR(par2, par1, SZ(inp)) if(c != par1 && c != par2) {
            F0R(i, SZ(inp[c])) if(inp[c][i] != inp[par1][i] && inp[c][i] != inp[par2][i]) goto endPar;

            adj[c].pb(par1);
            adj[c].pb(par2);
            adj[par1].pb(c);
            adj[par2].pb(c);
            goto endC;
            endPar: ;
        }
        endC: ;
    }

    int mxAmt = 0;
    int mxNums = 0;
    F0R(i, SZ(inp)) {
        auto [amt, nums] = dfs(i);
        if(ckmax(mxAmt, amt)) mxNums = nums;
    }
    cout << mxNums << endl;
}

