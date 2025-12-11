#include "../utils.cc"

void solve() {
    map<string, int> toI;
    map<int, string> fromI;
    vvi adj, adjR;
    vi in;
    auto getIndex = [&](string& s) {
        if(toI.count(s)) return toI[s];

        toI[s] = SZ(toI);
        fromI[SZ(fromI)] = s;
        adj.eb();
        adjR.eb();
        in.pb(0);
        return toI[s];
    };

    getInp([&](auto& inS, int) {
        string inp, out;
        inS >> inp;

        inp.pop_back();
        int inpI = getIndex(inp);

        while(inS >> out) {
            int outI = getIndex(out);
            adj[inpI].pb(outI);
            adjR[outI].pb(inpI);
            in[outI]++;
        }
    });

    vi q;
    F0R(i, SZ(adj)) 
        if(!in[i]) q.pb(i);
    F0R(i, SZ(q))
        for(int v : adj[q[i]])
            if(!--in[v])
                q.pb(v);
    assert(SZ(q) == SZ(adj));


    vector<ll> res(SZ(q));
    res[toI["you"]] = 1;
    for(int i : q)
        for(int v : adj[i])
            res[v] += res[i];
    cout << res[toI["out"]] << endl;
}

