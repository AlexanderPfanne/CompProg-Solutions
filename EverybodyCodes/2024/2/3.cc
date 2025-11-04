#include "../utils.cc"

vector<string> grid;
set<ii> ps;
vector<ii> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void match(string& w, int i, int j) {
    for(auto [dr, dc] : dirs) {
        bool ok = true;
        F0R(k, SZ(w)) 
            ok &= i + dr*k >= 0 && i + dr*k < SZ(grid) &&
                  grid[i + dr*k][(j + dc*k + SZ(grid[0])) % SZ(grid[0])] == w[k];
        if(ok) 
            F0R(k, SZ(w)) ps.emplace(i + dr*k, (j + dc*k + SZ(grid[0])) % SZ(grid[0]));
    }
}

void solve() {
    vector<string> ss = getInp();
    vector<string> words = split(ss[0].substr(6), ",");
    FOR(i, 2, SZ(ss)) grid.pb(ss[i]);

    F0R(i, SZ(grid)) F0R(j, SZ(grid[0]))
        for(string w : words)
            match(w, i, j);

    cout << SZ(ps) << endl;
}

