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

    for(int i = 0; i < SZ(inp); i += 3) {
        int amt = 3 - (inp[i] == 'x') - (inp[i + 1] == 'x') - (inp[i + 2] == 'x');
        if(amt == 3) res += 6;
        if(amt == 2) res += 2;
        res += m[inp[i]] + m[inp[i + 1]] + m[inp[i + 2]];
    }
    cout << res << endl;
}

