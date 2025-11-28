#include "../utils.cc"

vi dr = {1, -1, 0, 0},
   dc = {0, 0, 1, -1};
vector<string> ss;

set<ii> doExplosion(ii start, set<ii>& old_seen) {
    if(old_seen.count(start)) return set<ii>();

    set<ii> seen;
    queue<ii> q;
    q.push(start);
    seen.insert(start);

    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])
                || old_seen.count(mp(rr, cc)) 
                || seen.count(mp(rr, cc))
                || ss[rr][cc] > ss[r][c]) continue;
            seen.emplace(rr, cc);
            q.emplace(rr, cc);
        }
    }
    return seen;
}

void solve() {
    ss = getInp();

    set<ii> seen;
    F0R(i, 3) {
        set<ii> bestSeen;
        F0R(r, SZ(ss)) F0R(c, SZ(ss[0])) {
            set<ii> currSeen = doExplosion(mp(r, c), seen);
            if(SZ(currSeen) > SZ(bestSeen)) bestSeen = currSeen;
        }
        seen.insert(ALL(bestSeen));
    }
    cout << SZ(seen) << endl;

}

