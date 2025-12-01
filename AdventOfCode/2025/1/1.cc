#include "../utils.cc"

void solve() {
    ll res = 0, pos = 50;
    getInp([&](auto& in, int) {
        char c; int i;
        in >> c >> i;

        if(c == 'L') pos -= i;
        else pos += i;

        pos = ((pos % 100) + 100) % 100;
        if(!pos) res++;
    });

    cout << res << endl;
}

