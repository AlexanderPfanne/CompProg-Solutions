#include "../utils.cc"

struct DSU {
    DSU(int size) : msize(size), data(size, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (data[a] > data[b]) swap(a, b);
        data[a] += data[b], data[b] = a;
        return --msize, true;
    }
    int size() { return msize; }
    int size(int a) { return -data[find(a)]; }
    int msize;
    vi data;
};

typedef tuple<ll, ll, ll> ll3;

ll dist(ll3& a, ll3& b) {
    auto [x, y, z] = (a - b)*(a - b);
    return sqrt(x + y + z);
}

void solve() {
    vector<ll3> inp;
    getInp([&](auto& in, int) {
        ll x, y, z; char _;
        in >> x >> _ >> y >> _ >> z;
        inp.eb(x, y, z);
    });

    set<ll3> dists;
    F0R(i, SZ(inp)) FOR(j, i + 1, SZ(inp))
        dists.emplace(dist(inp[i], inp[j]), i, j);

    DSU dsu(SZ(inp));
    F0R(_, 1000) {
        auto [d, i, j] = *dists.begin();
        dists.erase(dists.begin());
        if(dsu.find(i) == dsu.find(j)) continue;
        dsu.join(i, j);
    }

    set<int> seen;
    vi sizes;
    F0R(i, SZ(inp))
        if(seen.insert(dsu.find(i)).se)
            sizes.pb(dsu.size(dsu.find(i)));
    sort(RALL(sizes));

    cout << sizes[0] * sizes[1] * sizes[2] << endl;
}

