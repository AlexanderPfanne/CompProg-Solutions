#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        char c; string s;
        in >> c >> s;
        s.pop_back();

        vvi switches;
        while(1) {
            in >> c;
            if(c == '(') {
                switches.eb();
                do {
                    int x; in >> x >> c;
                    switches.back().pb(x);
                } while(c != ')');
            } else {
                assert(c == '{');
                // Not needed
                break;
            }
        }

        queue<pair<string, int>> q;
        set<string> seen;
        q.emplace(string(SZ(s), '.'), 0);
        seen.emplace(SZ(s), '.');
        while(SZ(q)) {
            auto [currS, t] = q.front();
            q.pop();

            for(vi& v : switches) {
                string newS = currS;
                for(int i : v) newS[i] = newS[i] == '#' ? '.' : '#';
                if(seen.insert(newS).se) {
                    if(newS == s) {
                        res += t + 1;
                        return;
                    }
                    q.emplace(newS, t + 1);
                }
            }
        }
        assert(false);
    });
    cout << res << endl;
}

