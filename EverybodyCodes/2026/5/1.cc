#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    int R = SZ(ss);
    int C = SZ(ss[0]);


    set<ii> land;
    land.emplace(R/2, C/2);
    ss[R/2][C/2] = '#';

    for(bool change = true; change;) {
        change = false;
        for(auto [r, c] : land) {
            FOR(dr, -1, 2) FOR(dc, -1, 2) {
                int rr = r + dr, cc = c + dc;
                if(min(rr, cc) < 0 || rr >= R || cc >= C) continue;
                if(ss[rr][cc] == '#') continue;

                int cnt = 0;
                FOR(drr, -1, 2) FOR(dcc, -1, 2) {
                    int rrr = rr + drr, ccc = cc + dcc;
                    cnt += (drr || dcc)
                        && min(rrr, ccc) >= 0 && rrr < R && ccc < C
                        && ss[rrr][ccc] != '0';
                }

                if(cnt >= 5) {
                    change = true;
                    land.emplace(rr, cc);
                    ss[rr][cc] = '#';
                }
            }
        }
    }


    cout << SZ(land) << endl;
}

