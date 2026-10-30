#include "../utils.cc"

void solve() {
    ll res = 0, x;
    char c;
    do {
        cin >> x;
        int i = 1;
        while(i*i < x) ++i;
        res += i*i - x;
    } while(cin >> c);

    cout << res << endl;
}

