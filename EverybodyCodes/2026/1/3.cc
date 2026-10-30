#include "../utils.cc"

void solve() {
    ll res = 0, x;
    char c;
    do {
        cin >> x;
        int i = 3;
        while(i*i - 1 < x) i += 2;
        res += i*i-1 - x;
        dout << dvar(i, x, i*i - 1 - x) << endl;
    } while(cin >> c);

    cout << res << endl;
}

