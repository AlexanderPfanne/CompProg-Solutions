#include "../utils.cc"

ll pow(ll a, ll p) {
    if(!p) return 1;
    if(p == 1) return a;
    if(p & 1) return a * pow(a, p - 1);
    
    ll x = pow(a, p/2);
    return x*x;
}

void solve() {
    ll res = 0;
    vector<ll> inp;
    vector<string> ss = getInp([&](auto& in, int) {
        char c; ll x, y;
        in >> c >> c >> c >> c >> x >> y;

        for(int i = 0; x; ++i) {
            res += pow(x % 10, i) * (y % 10);
            y /= 10;
            x /= 10;
        }
    });

    cout << res << endl;
}

