#include "../utils.cc"

void solve() {
    vii pts;
    getInp([&](auto& in, int) {
        char _; int x, y; in >> x >> _ >> y;
        pts.eb(x, y);
    });

    sort(ALL(pts), [&](ii a, ii b) { return a.fi + a.se < b.fi + b.se; });

    ll res = 0;
    int lastX = 0, lastY = 0;
    for(auto [x, y] : pts) {
        res += max(abs(lastX - x), abs(lastY - y));
        lastX = x;
        lastY = y;
    }
    cout << res << endl;
}

