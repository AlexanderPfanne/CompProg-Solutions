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
        char c; string x, y;
        in >> c >> c >> c >> c >> x  >> y;

        int xI = SZ(x) - 1;
        for(int i = SZ(y) - 1; ~i; --i) {
            
            int cx = x[xI] - '0';
            if(--xI < 0) xI = SZ(x) - 1;

            int cy = y[i] - '0';
            res += pow(cx, SZ(y) - i - 1) * cy;
        }
    });

    cout << res << endl;
}

