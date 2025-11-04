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

    for(string m : moves) {
        int amt = stoi(m.substr(1));
        if(m[0] == 'R') swap(inp[0], inp[amt % SZ(inp)]);
        else swap(inp[0], inp[(SZ(inp) - amt % SZ(inp)) % SZ(inp)]);
    }
    cout << inp[0] << endl;
}

