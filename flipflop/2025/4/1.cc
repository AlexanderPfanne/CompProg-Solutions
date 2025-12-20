#include "../utils.cc"

void solve() {
    ll res = 0;
    int lastX = 0, lastY = 0;
    getInp([&](auto& in, int) {
        char _; int x, y; in >> x >> _ >> y;
        res += abs(lastX - x) + abs(lastY - y);
        lastX = x;
        lastY = y;
    });
    cout << res << endl;
}

