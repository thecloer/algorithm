#include <iostream>
using namespace std;

int dp[1000001];
inline int min(int a, int b) {return a < b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1];
        if((i % 3) == 0) dp[i] = min(dp[i], dp[i/3]);
        if((i & 1) == 0) dp[i] = min(dp[i], dp[i/2]);
        dp[i]++;
    }
    cout << dp[N];
}