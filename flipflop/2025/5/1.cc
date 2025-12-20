#include "../utils.cc"

void solve() {
    ll res = 0;
    getInp([&](auto& in, int) {
        string s; in >> s;
        for(int pos = 0; pos < SZ(s); ++pos) {
            int target = -1;
            F0R(i, SZ(s)) if(s[i] == s[pos] && i != pos) target = i;
            assert(target != -1);
            res += abs(target - pos);
            pos = target;
        }
    });

    cout << res << endl;
}

