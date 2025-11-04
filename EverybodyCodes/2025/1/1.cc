#include "../utils.cc"

void solve() {
    vector<string> inp, moves;
    getInp([&](auto& cin, int i) {
        string s;
        if(!i) {
            cin >> s;
            inp = split(s, ",");
        } else if(i == 2) {
            cin >> s;
            moves = split(s, ",");
        }
    });

    int pos = 0;
    for(string m : moves) {
        int amt = stoi(m.substr(1));
        if(m[0] == 'R') pos = min(SZ(inp) - 1, pos + amt);
        else pos = max(0, pos - amt);
    }
    cout << inp[pos] << endl;
}

