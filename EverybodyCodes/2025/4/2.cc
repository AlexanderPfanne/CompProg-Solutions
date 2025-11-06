#include "../utils.cc"

void solve() {
    vector<ll> inp;
    getInp([&](auto& cin, int) {
        int x; cin >> x;
        inp.pb(x);
    });

    double perRot = (double)inp[0]/inp.back();
    double target = 10000000000000.0;
    cout << (ll)((target + perRot - 1)/perRot) << endl;
}

