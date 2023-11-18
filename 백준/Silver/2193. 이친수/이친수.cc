#include <iostream>
using namespace std;

long long dp[91] = {0, 1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=2; i<=N; i++)
        dp[i] = dp[i-1] + dp[i-2];
    cout << dp[N];
}