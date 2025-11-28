#include "../utils.cc"

vi dr = {1, -1, 0, 0},
   dc = {0, 0, 1, -1};

void solve() {
    vector<string> ss = getInp();

    set<ii> seen;
    queue<ii> q;
    q.emplace(0, 0);
    seen.emplace(0, 0);

    while(SZ(q)) {
        auto [r, c] = q.front();
        q.pop();

        F0R(i, 4) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            if(min(rr, cc) < 0 || rr >= SZ(ss) || cc >= SZ(ss[0])
                || seen.count(mp(rr, cc))
                || ss[rr][cc] > ss[r][c]) continue;
            seen.emplace(rr, cc);
            q.emplace(rr, cc);
        }
    }

    cout << SZ(seen) << endl;
}

