#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        string s; in >> s;
        assert(SZ(s) % 2 == 0);

        bool ok = true;
        F0R(i, SZ(s)/2) ok &= s[i*2 + 1] == 'a';
        if(ok) res += SZ(s)/2;
    });
    cout << res << endl;
}

