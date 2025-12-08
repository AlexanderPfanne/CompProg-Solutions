#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp();

    queue<ii> q;
    set<ii> seen;

    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] == 'S') {
        q.emplace(r, c);
        seen.emplace(r, c);
        break;
    }

    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        if(r == SZ(ss) - 1) continue;

        if(ss[r + 1][c] == '^') {
            res++;
            if(c - 1 >= 0 && !seen.count(mp(r + 1, c - 1))) {
                q.emplace(r + 1, c - 1);
                seen.emplace(r + 1, c - 1);
            }
            if(c + 1 < SZ(ss[0]) && !seen.count(mp(r + 1, c + 1))) {
                q.emplace(r + 1, c + 1);
                seen.emplace(r + 1, c + 1);
            }
        } else if(!seen.count(mp(r + 1, c))) {
            seen.emplace(r + 1, c);
            q.emplace(r + 1, c);
        }
    }


    cout << res << endl;
}

