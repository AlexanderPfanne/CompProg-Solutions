#include "../utils.cc"

void solve() {
    map<ll, map<ll, vector<pair<ll, ll>>>> qps;
    set<ll> qs;
    set<ll> ppl;

    getInp([&](auto& in, int) {
        char c; ll id, q, p, t;
        in >> c >> c >> c >> id 
           >> c >> c >> c >> c >> c >> c >> q
           >> c >> c >> c >> c >> c >> p
           >> c >> c >> c >> c >> c >> t;

        --id;

        qps[q][p].eb(id, t);
        qs.insert(q);
        ppl.insert(id);
    });

    map<ll, ll> scores;
    for (ll q : qs) {
        map<ll, ll> timePrev;

        FOR(p, 1, 4) {
            vi inds(SZ(qps[q][p]));
            iota(ALL(inds), 0);
            F0R(i, SZ(inds)) timePrev[qps[q][p][i].fi] += qps[q][p][i].se;

            sort(ALL(inds), [&](int a, int b) {
                    return timePrev[qps[q][p][a].fi] < timePrev[qps[q][p][b].fi];
                });

            int currScore = p == 1 ? 50 : (p == 2 ? 100 : 150);
            int scoreBuffer = 0;
            F0R(i, SZ(inds)) {
                if(i > 0) scoreBuffer++;
                if(i > 0 && timePrev[qps[q][p][inds[i]].fi] != timePrev[qps[q][p][inds[i - 1]].fi]) {
                    currScore = max(currScore - scoreBuffer, 0);
                    scoreBuffer = 0;
                }
                scores[qps[q][p][inds[i]].fi] += currScore;
            }
        }
    }

    vector<ll> fScores;
    for(auto [k, v] : scores) fScores.pb(v);
    sort(RALL(fScores));

    ll res = 0;
    int currTimes = 1;
    int timesBuffer = 0;
    F0R(i, SZ(fScores)) {
        if(i > 0) timesBuffer++;
        if(i > 0 && fScores[i] != fScores[i - 1]) {
            currTimes += timesBuffer;
            timesBuffer = 0;
        }
        res += currTimes * fScores[i];
    }
    cout << res << endl;
}

