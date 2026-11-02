#include "../utils.cc"

map<string, vector<string>> adj;

void dfs(string curr, set<string>& seen) {
    if(seen.count(curr)) return;
    seen.insert(curr);
    for(string& x : adj[curr]) dfs(x, seen);
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

    set<string> seen1, seen2, seen3;
    dfs("NULLv1", seen1);
    dfs("NULLv2", seen2);
    dfs("NULLv3", seen3);

    set<string> seen12 = seen1 & seen2,
                seen13 = seen1 & seen3,
                seen23 = seen2 & seen3,
                seen = seen12 | seen13 | seen23;
    cout << SZ(seen) - seen.count("NULLv1") - seen.count("NULLv2") - seen.count("NULLv3") << endl;

}

