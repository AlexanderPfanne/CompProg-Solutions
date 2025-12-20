#include "../utils.cc"

void solve() {
    const ll T = 31556926;
    const int SKY = 1000;
    const int PIC = 500;

    ll res = 0;
    getInp([&](auto& in, int) {
        char _; ll xvel, yvel; in >> xvel >> _ >> yvel;
        F0R(i, 1000) {
            int x = ((xvel*T*i) % SKY + SKY) % SKY;
            int y = ((yvel*T*i) % SKY + SKY) % SKY;
            res += (x >= PIC/2 && x < PIC*3/2) && (y >= PIC/2 && y < PIC*3/2);
        }
    });

    cout << res << endl;
}

