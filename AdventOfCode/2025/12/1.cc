#include "../utils.cc"

void solve() {
    vi sizes;

    string s; cin >> s;
    while(1) {
        if(s[1] != ':') break;

        vector<string> shape;
        while(cin >> s && !isdigit(s[0]))
            shape.pb(s);

        sizes.pb(0);
        F0R(i, 3) F0R(j, 3) sizes.back() += shape[i][j] == '#';

    }

    ll res = 0;
    do {
        assert(isdigit(s[0]));
        auto [w, h] = splitP(s, "x");

        ll gridSize = stoll(w)*stoll(h);
        ll presentSize = 0;
        for(int sz : sizes) {
            int x; cin >> x;
            presentSize += x*sz;
        }

        // Hard case hopefully doesnt happen??
        if(presentSize * 1.2 < gridSize) ++res;
        else if(presentSize <= gridSize) assert(false);
    } while(cin >> s);
    cout << res << endl;
}

