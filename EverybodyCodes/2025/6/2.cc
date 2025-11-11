#include "../utils.cc"

void solve() {
    string s = getInp()[0];



    ll res = 0;
    ll curr = 0;
    for(char c : s) {
        if(c == 'A') ++curr;
        if(c == 'a') res += curr;
    }

    cout << res << endl;
}

