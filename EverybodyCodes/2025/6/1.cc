#include "../utils.cc"

void solve() {
    string s = getInp()[0];

    ll res = 0;
    ll currA = 0, currB = 0, currC = 0;;
    for(char c : s) {
        if(c == 'A') ++currA;
        if(c == 'a') res += currA;
        if(c == 'B') ++currB;
        if(c == 'b') res += currB;
        if(c == 'C') ++currC;
        if(c == 'c') res += currC;
    }

    cout << res << endl;
}

