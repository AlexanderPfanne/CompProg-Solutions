#include "../utils.cc"

ll pow(ll a, ll p) {
    if(!p) return 1;
    if(p == 1) return a;
    if(p & 1) return a * pow(a, p - 1);
    
    ll x = pow(a, p/2);
    return x*x;
}

ll comp(ll xll, ll yll) {
    string x = to_string(xll);
    string y = to_string(yll);

    ll val = 0;
    int xI = SZ(x) - 1;
    for(int i = SZ(y) - 1; ~i; --i) {
        
        int cx = x[xI] - '0';
        if(--xI < 0) xI = SZ(x) - 1;

        int cy = y[i] - '0';
        val += pow(cx, SZ(y) - i - 1) * cy;
    }
    return val;
}

void solve() {
    ll res = 0;
    vector<ll> inp;
    vector<string> ss = getInp([&](auto& in, int) {
        char c; ll x, y;
        in >> c >> c >> c >> c >> c >> x  >> y;

        ll target = comp(x, y);

        for(ll i = 0; ; ++i) {
            if(target == comp(x, i)) {
                if(i == y) res += target;
                break;
            }
                  
        }
    });

    cout << res << endl;
}

