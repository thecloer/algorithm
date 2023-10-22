#include <iostream>
using namespace std;

int dp[11];

int fibo(int x) {
    if(dp[x]) return dp[x];
    return fibo(x-1) + fibo(x-2) + fibo(x-3);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    dp[0] = dp[1] = 1; dp[2] = 2;
    while(T--) {
        int n; cin >> n;
        cout << fibo(n) << '\n';
    }
}