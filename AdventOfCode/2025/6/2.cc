#include "../utils.cc"

void solve() {
    vector<string> ss = getInp();

    auto getNum = [&](int i) {
        ll n = 0;
        F0R(j, SZ(ss) - 1) if(ss[j][i] != ' ') n = n*10 + (ss[j][i] - '0');
        if(!n) return optional<ll>{};
        return optional(n);
    };
    auto getTotal = [&](char op, vector<ll>& nums) {
        ll total = op == '*';
        F0R(j, SZ(nums)) {
            if(op == '*') total *= nums[j];
            else if(op == '+') total += nums[j];
            else assert(false);
        }
        return total;
    };

    ll res = 0;
    vector<ll> nums;
    char op = '?';
    F0R(i, SZ(ss.back())) {
        if(ss.back()[i] != ' ') {
            if(i) res += getTotal(op, nums);
            op = ss.back()[i];
            nums.clear();
        }
        if(getNum(i)) nums.pb(*getNum(i));
    }
    res += getTotal(op, nums);

    cout << res << endl;
}

