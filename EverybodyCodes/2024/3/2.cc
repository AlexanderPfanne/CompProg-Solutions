#include "../utils.cc"

vii ds = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve() {
    vector<string> ss = getInp();
    
    map<ii, int> dist;
    queue<ii> q;
    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
        if(ss[r][c] == '#') {
            for(auto [dr, dc] : ds) {
                if(ss[r + dr][c + dc] == '.') {
                    dist[mp(r, c)] = 1;
                    q.emplace(r, c);
                }
            }
        }
    }

    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        for(auto [dr, dc] : ds) {
            if(!dist.count(mp(r + dr, c + dc)) && ss[r + dr][c + dc] == '#') {
                dist[mp(r + dr, c + dc)] = dist[mp(r, c)] + 1;
                q.emplace(r + dr, c + dc);
            }
        }
    }

    ll res = 0;
    for(auto [a, b] : dist) res += b;
    cout << res << endl;
}

