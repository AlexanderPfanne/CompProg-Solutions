#include "../utils.cc"

void solve() {
    ll res = 0, curr = 0;
    getInp([&](auto& in, int) {
        char c;
        while(in >> c) {
            curr += c == '^' ? 1 : -1;
            ckmax(res, curr);
        }
    });
    cout << res << endl;
}

