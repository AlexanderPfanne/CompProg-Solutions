#include "../utils.cc"

ll fib(int n) {
    if(!n) return 0;
    if(n == 1) return 1;

    static map<int, ll> dp;
    if(dp.count(n)) return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

void solve() {
    ll res = 0, curr = 0, consec = 0;
    getInp([&](auto& in, int) {
        char c, last = '?';
        while(in >> c) {
            if(c == last) {
                ++consec;
            } else {
                curr += last == '^' ? fib(consec) : -fib(consec);
                ckmax(res, curr);
                consec = 1;
            }
            last = c;
        }
        curr += last == '^' ? fib(consec) : -fib(consec);
        ckmax(res, curr);
    });
    cout << res << endl;
}

