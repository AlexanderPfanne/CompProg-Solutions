#include "../utils.cc"

bool isOk(ll n) {
    string s = to_string(n);
    FOR(i, 1, SZ(s)/2 + 1) {
        if(SZ(s) % i) continue;

        bool match = true;
        F0R(j, i)
            FOR(k, 1, SZ(s)/i)
                match &= s[j] == s[j + k*i];
        if(match) return false;
    }
    return true;
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

