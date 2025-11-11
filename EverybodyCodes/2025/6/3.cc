#include "../utils.cc"

void solve() {
    string s = getInp()[0];
    const int MUL = 1000;
    const int INTERVAL = 1000;

    map<char, vector<ll>> pref;
    F0R(i, SZ(s)) {
        for(auto& [a, v] : pref) v[i] = v[i - 1];
        if(!pref.count(s[i])) pref[s[i]] = vector<ll>(SZ(s), 0);
        pref[s[i]][i]++;
    }

    ll res = 0;
    F0R(i, MUL*SZ(s)) {
        if(!islower(s[i % SZ(s)])) continue;
        char c = toupper(s[i % SZ(s)]);

        int hi = min(i + INTERVAL, MUL*SZ(s) - 1);
        int lo = max(i - INTERVAL, 0);

        if(hi % SZ(s) < lo % SZ(s)) {
            res += pref[c][hi % SZ(s)] + (pref[c][SZ(s) - 1] - pref[c][lo % SZ(s)]);
            hi -= hi % SZ(s) + (SZ(s) - lo % SZ(s));
        } else if(hi % SZ(s) > lo % SZ(s)) {
            res += pref[c][hi % SZ(s)] - pref[c][lo % SZ(s)];
            hi -= (hi - lo) % SZ(s);
        }
        assert(hi % SZ(s) == lo % SZ(s));

        while(hi > lo) {
            res += pref[c][SZ(s) - 1];
            hi -= SZ(s);
        }
        assert(hi == lo);
        res += s[hi % SZ(s)] == c;
    }
    cout << res << endl;
}

