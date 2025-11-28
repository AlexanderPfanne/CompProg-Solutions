#include "../utils.cc"

bool doRound(vector<ll>& inp, bool phase2 = false) {
    bool change = false;
    F0R(i, SZ(inp) - 1) {
        if(!phase2 && inp[i] > inp[i + 1]) {
            --inp[i];
            ++inp[i + 1];
            change = true;
        } else if(phase2 && inp[i] < inp[i + 1]) {
            ++inp[i];
            --inp[i + 1];
            change = true;
        }
    }
    return change;
}

void solve() {
    vector<ll> inp;
    getInp([&](auto& in, int) {
        ll i; in >> i; inp.pb(i);
    });

    int cnt = 0;
    for(int noChange = !doRound(inp, false); 
            noChange < 2; 
            noChange += !doRound(inp, noChange)) {
        ++cnt;
    }
    cout << cnt - 1 << endl;
}

