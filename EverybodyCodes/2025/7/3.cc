#include "../utils.cc"

void solve() {
    vector<string> names;
    map<char, vector<char>> prio;
    getInp([&](auto& cin, int i) {
        if(!i) {
            string s; cin >> s;
            names = split(s, ",");
        } else if(i > 1) {
            char c, r;
            cin >> c >> r >> r;
            if(!prio.count(c)) prio[c] = vector<char>();
            do {
                prio[c].pb(r);
            } while(cin >> r >> r);
        }
    });

    ll res = 0;
    set<string> seen;
    F0R(j, SZ(names)) {
        string& s = names[j];
        bool ok = true;
        F0R(i, SZ(s) - 1)
            ok &= count(ALL(prio[s[i]]), s[i + 1]);
        
        if(ok) {
            queue<string> q;
            q.push(s);
            seen.insert(s);
            while(SZ(q)) {
                string curr = q.front();
                q.pop();
                if(SZ(curr) >= 7) ++res;
                if(SZ(curr) >= 11) continue;
                for(char c : prio[curr[SZ(curr) - 1]]) {
                    if(seen.count(curr + c)) continue;
                    seen.insert(curr + c);
                    q.push(curr + c);
                }
            }

        }
    }
    cout << res << endl;
}

