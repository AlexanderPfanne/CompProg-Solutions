#include "../utils.cc"

void solve() {
    vector<string> ns = split(getInp()[0], ",");
    vi nums;
    for(string& s : ns) nums.pb(atoi(s.c_str()));
    sort(ALL(nums));
    
    int last = 1e9, i = 1, res = 0;
    for(int n : nums) {
        if(n == last) ckmax(res, ++i);
        else i = 1;
        last = n;
    }
    cout << res << endl;
}

