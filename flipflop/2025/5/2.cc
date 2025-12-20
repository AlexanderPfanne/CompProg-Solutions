#include "../utils.cc"

void solve() {
    getInp([&](auto& in, int) {
        set<char> seen;
        string s; in >> s;
        for(int pos = 0; pos < SZ(s); ++pos) {
            seen.insert(s[pos]);
            int target = -1;
            F0R(i, SZ(s)) if(s[i] == s[pos] && i != pos) target = i;
            assert(target != -1);
            pos = target;
        }
        F0R(i, SZ(s)) if(seen.insert(s[i]).se) cout << s[i];
        cout << endl;
    });
}

