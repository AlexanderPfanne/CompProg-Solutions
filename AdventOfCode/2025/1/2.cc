#include "../utils.cc"

void solve() {
    ll res = 0, pos = 50;
    getInp([&](auto& in, int) {
        char c; int i;
        in >> c >> i;
        
        res += i / 100;
        i %= 100;

        if(c == 'L') {
            res += i && pos && pos - i <= 0;
            pos -= i;
        } else {
            res += i && pos + i >= 100;
            pos += i;
        }

        pos = ((pos % 100) + 100) % 100;
    });

    cout << res << endl;
}

