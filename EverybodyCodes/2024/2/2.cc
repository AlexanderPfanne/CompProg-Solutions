#include "../utils.cc"

bool matches(string& t, string& w, int i) {
    F0R(j, SZ(w))
        if(t[i + j] != w[j]) return false;
    return true;
}

void solve() {
    ll res = 0;
    vector<string> ss = getInp();
    vector<string> words = split(ss[0].substr(6), ",");
    vector<string> text;
    FOR(i, 2, SZ(ss)) {
        vector<string> ts = split(ss[i], " ");
        text.insert(text.end(), ALL(ts));
    }

    for(string t : text) {
        set<int> is;
        for(string w : words) {
            F0R(i, SZ(t) - SZ(w) + 1)
                if(matches(t, w, i))
                    F0R(j, SZ(w)) is.insert(i + j);
            reverse(ALL(t));
            F0R(i, SZ(t) - SZ(w) + 1)
                if(matches(t, w, i))
                    F0R(j, SZ(w)) is.insert(SZ(t) - 1 - (i + j));
            reverse(ALL(t));
        }
        res += SZ(is);
    }

    cout << res << endl;
}

