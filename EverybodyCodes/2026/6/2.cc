#include "../utils.cc"

map<string, vector<string>> adj;
set<string> seen;

void dfs(string curr) {
    if(seen.count(curr)) return;
    seen.insert(curr);
    for(string& x : adj[curr]) dfs(x);
}

void solve() {

    getInp([&](auto& in, int) {
        string item = "", s;
        in >> s;

        vector<string> ings(1, "");

        bool isItem = false;
        F0R(i, SZ(s)) {
            if(!isItem) {
                if(s[i] == ':') isItem = true;
                else item += s[i];
            } else {
                if(s[i] == ',') ings.pb("");
                else ings.back().pb(s[i]);
            }
        }

        for(string& ing : ings) adj[ing].pb(item);
    });

    dfs("NULL");

    cout << SZ(seen) - 1 << endl;
}

