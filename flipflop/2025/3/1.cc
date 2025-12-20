#include "../utils.cc"

void solve() {
    map<tuple<int, int, int>, int> amts;
    getInp([&](auto& in, int) {
        char _; int r, g, b; in >> r >> _ >> g >> _ >> b;
        amts[mt(r, g, b)]++;
    });

    int res = 0;
    tuple<int, int, int> resC;
    for(auto [c, n] : amts) if(ckmax(res, n)) resC = c;
    cout << pp(resC, ",") << endl;
}

