#include "../utils.cc"

void solve() {
    vector<pair<ll, ll>> inp;
    getInp([&](auto& in, int) {
        char _; ll i, j;
        in >> i >> _ >> j;
        inp.eb(i, j);
    });

    vector<pair<ll, ll>> wheel(SZ(inp) + 1, mp(1, 1));

    F0R(i, SZ(inp)) {
        if(i & 1) wheel[SZ(wheel) - 1 - i/2] = mp(inp[i].se, inp[i].fi);
        else wheel[i/2 + 1] = inp[i];
    }

    int currPos = 0;
    ll toGo = 20252025ll;
    while(1) {
        auto [p1, p2] = wheel[currPos];
        int amt = max(p1, p2) - min(p1, p2) + 1;
        if(toGo > amt) {
            currPos = (currPos + 1) % SZ(wheel);
            toGo -= amt;
        } else {
            if(p1 <= p2) cout << p1 + toGo << endl;
            else cout << p1 - toGo << endl;
            return;
        }
    }
}

