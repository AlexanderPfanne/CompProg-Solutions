#include "../utils.cc"

void solve() {
    ll res = 0;

    map<int, ll> times;

    vector<string> ss = getInp([&](auto& in, int) {
        char c; int id, q, p, t;
        in >> c >> c >> c >> id 
           >> c >> c >> c >> c >> c >> c >> q
           >> c >> c >> c >> c >> c >> p
           >> c >> c >> c >> c >> c >> t;

        times[id] += t;
    });

    vector<ll> ts;
    for (auto [k, v] : times) ts.pb(v);
    sort(ALL(ts));
    F0R(i, SZ(ts)) res += (i + 1) * ts[i];

    cout << res << endl;
}

