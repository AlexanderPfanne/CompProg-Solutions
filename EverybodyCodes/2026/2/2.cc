#include "../utils.cc"

void solve() {
    ll res = 0;

    getInp([&](auto& in, int) {

        map<int, int> inCnt;
        set<int> pts;
        map<int, vi> adj;

        int a, b; char c;
        while (in >> a >> c >> b) {
            if(c == '<') swap(a, b);

            pts.insert(a);
            pts.insert(b);
            adj[a].pb(b);
            inCnt[b]++;
        }

        queue<ll> ok;
        for (int pt : pts) {
            if(!inCnt[pt]) {
                ok.push(pt);
                pts.erase(pt);
            }
        }

        int num = 0;
        while(SZ(ok)) {
            int x = ok.front();
            ok.pop();
            num = num*10 + x;

            for (ll y : adj[x]) {
                if(!--inCnt[y] && pts.count(y)) {
                    ok.push(y);
                    pts.erase(y);
                }
            }
        }
        res += num;
    });

    cout << res << endl;
}

