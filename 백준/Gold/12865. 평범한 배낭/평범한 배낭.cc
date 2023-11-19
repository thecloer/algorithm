#include <iostream>
using namespace std;

int dp[100001];
inline int max(int a, int b) {return a > b ? a : b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K, w, v; cin >> N >> K;
    while(N--) {
        cin >> w >> v;
        for(int i = K; i >= w; i--)
            dp[i] = max(dp[i], v + dp[i - w]);
    }
    cout << dp[K];
}