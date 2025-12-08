#include "../utils.cc"

void solve() {
    ll res = 0;
    vector<string> ss = getInp();

    queue<ii> q;
    set<ii> seen;
    map<ii, ll> cnt;

    F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) if(ss[r][c] == 'S') {
        q.emplace(r, c);
        cnt[mp(r, c)] = 1;
        break;
    }

    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        if(r == SZ(ss) - 1) {
            res += cnt[mp(r, c)];
            continue;
        }

        if(ss[r + 1][c] == '^') {
            if(c - 1 >= 0) {
                cnt[mp(r + 1, c - 1)] += cnt[mp(r, c)];
                if(!seen.count(mp(r + 1, c - 1))) {
                    q.emplace(r + 1, c - 1);
                    seen.emplace(r + 1, c - 1);
                }
            }
            if(c + 1 < SZ(ss[0])){
                cnt[mp(r + 1, c + 1)] += cnt[mp(r, c)];
                if(!seen.count(mp(r + 1, c + 1))) {
                    q.emplace(r + 1, c + 1);
                    seen.emplace(r + 1, c + 1);
                }
            }
        } else {
            cnt[mp(r + 1, c)] += cnt[mp(r, c)];
            if(!seen.count(mp(r + 1, c))) {
                seen.emplace(r + 1, c);
                q.emplace(r + 1, c);
            }
        }
    }


    cout << res << endl;
}

