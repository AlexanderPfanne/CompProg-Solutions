#include "../utils.cc"

void solve() {
    ll res = 0, vel = 0, curr = 0;
    getInp([&](auto& in, int) {
        char c;
        while(in >> c) {
            if((vel > 0 && c == 'v') || (vel < 0 && c == '^')) vel = 0;
            vel += c == '^' ? 1 : -1;
            ckmax(res, curr += vel);
        }
    });
    cout << res << endl;
}

