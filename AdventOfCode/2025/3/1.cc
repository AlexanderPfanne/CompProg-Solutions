#include "../utils.cc"

string turnOn(string& s, int amt, int startI = 0) {
    if(!amt) return "";

    int ind = startI;
    FOR(i, startI + 1, SZ(s) - amt + 1)
        if(s[i] > s[ind])
            ind = i;

    return s[ind] + turnOn(s, amt - 1, ind + 1);
}

void solve() {
    vector<string> ss = getInp();

    ll res = 0;
    for(string& s : ss) {
        assert(SZ(s) >= 2);
        res += stoll(turnOn(s, 2));
    }
    cout << res << endl;
}

