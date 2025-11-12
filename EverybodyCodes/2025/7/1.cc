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

    for(string& s : names) {
        bool ok = true;
        F0R(i, SZ(s) - 1)
            ok &= count(ALL(prio[s[i]]), s[i + 1]);
        if(ok) cout << s << endl;
    }
}

