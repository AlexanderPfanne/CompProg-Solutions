#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        char _; int r, g, b; in >> r >> _ >> g >> _ >> b;
        res += g > max(r, b) && r != b;
    });
    cout << res << endl;
}

