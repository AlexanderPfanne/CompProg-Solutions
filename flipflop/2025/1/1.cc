#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        string s; in >> s;
        assert(SZ(s) % 2 == 0);
        res += SZ(s)/2;
    });
    cout << res << endl;
}

