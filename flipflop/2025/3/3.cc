#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        char _; int r, g, b; in >> r >> _ >> g >> _ >> b;
        if(b == r || r == g || b == g) res += 10;
        else if(g > max(r, b)) res += 2;
        else if(r > max(g, b)) res += 5;
        else res += 4;
    });
    cout << res << endl;
}

