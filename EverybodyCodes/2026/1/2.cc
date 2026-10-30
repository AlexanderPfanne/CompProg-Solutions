#include "../utils.cc"

void solve() {
    ll res = 0, x;
    char c;
    do {
        cin >> x;
        int i = 3;
        while(4*i-4 < x) ++i;
        res += 4*i-4 - x;
    } while(cin >> c);

    cout << res << endl;
}

