#include "../utils.cc"

bool isOk(ll n) {
    string s = to_string(n);
    if(SZ(s) & 1) return true;
    F0R(i, SZ(s)/2)
        if(s[i] != s[i + SZ(s)/2]) return true;
    return false;
}

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        ll n1, n2; char c;
        do {
            in >> n1 >> c >> n2;
            FOR(i, n1, n2 + 1)
                if(!isOk(i)) res += i;
        } while(in >> c);
    });
    cout << res << endl;
}

