#include "../utils.cc"

ll getAmt(int r, int c, int w) {
    if(!r && !c && !w) return 1;
    return (r ? getAmt(r - 1, c, w) : 0) + 
           (c ? getAmt(r, c - 1, w) : 0) + 
           (w ? getAmt(r, c, w - 1) : 0);
}

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        int r, c; in >> r >> c;
        res += getAmt(r - 1, c - 1, r - 1);
    });
    cout << res << endl;
}

