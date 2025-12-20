#include "../utils.cc"

ll getAmt(int r, int c) {
    if(!r && !c) return 1;
    return (r ? getAmt(r - 1, c) : 0) + 
           (c ? getAmt(r, c - 1) : 0);
}

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        int r, c; in >> r >> c;
        res += getAmt(r - 1, c - 1);
    });
    cout << res << endl;
}

