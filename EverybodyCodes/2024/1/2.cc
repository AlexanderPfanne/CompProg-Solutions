#include "../utils.cc"

void solve() {
    ll res = 0;
    string inp = getInp()[0];


    map<char, int> m = {
        mp('x', 0),
        mp('A', 0),
        mp('B', 1),
        mp('C', 3),
        mp('D', 5)
    };

    for(int i = 0; i < SZ(inp); i += 2) {
        if(inp[i] != 'x' && inp[i + 1] != 'x') res += 2;
        res += m[inp[i]] + m[inp[i + 1]];
    }
    cout << res << endl;
}

