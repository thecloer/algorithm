#include <iostream>
using namespace std;

int dp[12] = {1, 1, 2};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    int i=3;
    while(T--) {
        int n; cin >> n;
        if(!dp[n]) {
            while(i <= n) {
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
                i++;
            }
        }
        cout << dp[n] << '\n';
    }
}