#include <iostream>
using namespace std;

int T[15], P[15], dp[16];

inline int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> T[i] >> P[i];
    for(int i=N; i--;) dp[i] = (i+T[i] <= N) ? max(dp[i+1], P[i] + dp[i+T[i]]) : dp[i+1];
    cout << dp[0];
}