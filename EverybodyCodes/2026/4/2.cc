#include "../utils.cc"

void solve() {
    ll res = 0;

    map<int, ll> times;
    map<int, int> parts;

    getInp([&](auto& in, int) {
        char c; int id, q, p, t;
        in >> c >> c >> c >> id 
           >> c >> c >> c >> c >> c >> c >> q
           >> c >> c >> c >> c >> c >> p
           >> c >> c >> c >> c >> c >> t;

        --id;

        times[id] += t;
        parts[id]++;
    });

    vi inds(SZ(parts));
    iota(ALL(inds), 0);


    sort(ALL(inds), [&](int a, int b) {
                return parts[a] != parts[b] ? parts[a] > parts[b]
                                            : times[a] < times[b];
            });

    F0R(i, SZ(inds)) res += (i + 1) * times[inds[i]];

    cout << res << endl;
}

