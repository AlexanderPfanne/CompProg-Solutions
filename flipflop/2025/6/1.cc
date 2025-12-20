#include "../utils.cc"

void solve() {
    const int T = 100;
    const int SKY = 1000;
    const int PIC = 500;

    ll res = 0;
    getInp([&](auto& in, int) {
        char _; int x, y; in >> x >> _ >> y;
        x = ((x*T) % SKY + SKY) % SKY;
        y = ((y*T) % SKY + SKY) % SKY;
        dout << dvar(x, y) << endl;

        res += (x >= PIC/2 && x < PIC*3/2) && (y >= PIC/2 && y < PIC*3/2);
    });

    cout << res << endl;
}

