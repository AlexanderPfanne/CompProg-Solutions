#include "../utils.cc"

typedef pair<ll, ll> ll2;

ll area(ll2 a, ll2 b) {
    ll2 c = a - b;
    return (abs(c.fi) + 1) * (abs(c.se) + 1);
}

void solve() {
    vector<ll2> inp;
    getInp([&](auto& in, int) {
        ll a, b; char _;
        in >> a >> _ >> b;
        inp.eb(a, b);
    });

    ll res = 0;
    F0R(i, SZ(inp)) FOR(j, i + 1, SZ(inp)) {
        auto [mnX, mxX] = minmax(inp[i].fi, inp[j].fi);
        auto [mnY, mxY] = minmax(inp[i].se, inp[j].se);

        bool mnmn = false, mnmx = false, mxmn = false, mxmx = false;
        for(auto [x, y] : inp) {
            mnmn |= x <= mnX && y <= mnY;
            mnmx |= x <= mnX && y >= mxY;
            mxmn |= x >= mxX && y <= mnY;
            mxmx |= x >= mxX && y >= mxY;
        }
        if(!mnmn || !mnmx || !mxmn || !mxmx) continue;

        bool ok = true;
        F0R(k, SZ(inp)) {
            auto [x1, y1] = inp[k];
            auto [x2, y2] = inp[(k + 1) % SZ(inp)];
            ok &= (x1 <= mnX || mxX <= x1 || max(y1, y2) <= mnY || min(y1, y2) >= mxY)
               && (y1 <= mnY || mxY <= y1 || max(x1, x2) <= mnX || min(x1, x2) >= mxX);
        }
        if(!ok) continue;

        ckmax(res, area(inp[i], inp[j]));
    }
    cout << res << endl;
}

