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
    vector<string> text = split(ss[2], " ");

    for(string t : text) for(string w : words)
        F0R(i, SZ(t) - SZ(w) + 1)
            res += matches(t, w, i);

    cout << res << endl;
}

