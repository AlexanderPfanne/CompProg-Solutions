#include "../utils.cc"

void solve() {
    ll res = 0;
    string inp = getInp()[0];


    map<char, int> m = {
        mp('A', 0),
        mp('B', 1),
        mp('C', 3),
    };
    for(char c : inp) res += m[c];
    cout << res << endl;
}

