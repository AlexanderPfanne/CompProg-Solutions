#include "../utils.cc"

void solve() {
    vector<string> ns = split(getInp()[0], ",");
    vi nums;
    for(string& s : ns) nums.pb(atoi(s.c_str()));
    sort(ALL(nums));
    
    int last = 1e9;
    int i = 0;
    ll res = 0;
    for(int n : nums) {
        if(n != last) {
            res += n;
            ++i;
        }
        if(i == 20) break;
        last = n;
    }

    cout << res << endl;
}

