#include "../utils.cc"

void solve() {
    vector<ll> inp;
    getInp([&](auto& cin, int) {
        char c; int a;
        cin >> a >> c;
        while(cin >> a) {
            inp.pb(a);
            cin >> c;
        }
    });

    vi small, mid, big;
    small.pb(-1);
    mid.pb(inp[0]);
    big.pb(-1);

    FOR(i, 1, SZ(inp)) {
        bool placed = false;
        F0R(j, SZ(mid)) {
            if(inp[i] < mid[j] && small[j] == -1) {
                small[j] = inp[i];
                placed = true;
                break;
            } else if(inp[i] > mid[j] && big[j] == -1) {
                big[j] = inp[i];
                placed = true;
                break;
            }
        }
        if(!placed) {
            small.pb(-1);
            mid.pb(inp[i]);
            big.pb(-1);
        }
    }

    F0R(i, SZ(mid)) cout << mid[i];
}
