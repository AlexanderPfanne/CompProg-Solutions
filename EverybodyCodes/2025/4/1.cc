#include "../utils.cc"

void solve() {
    getInp([&](auto& cin, int) {
        int x; cin >> x;
        inp.pb(x);
    });

    cout << (int)(2025*(double)inp[0]/inp.back()) << endl;
}

