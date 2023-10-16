#include <iostream>
using namespace std;

int dp[100001];
int N, K;
int move(int k) {
    if(dp[k]) return dp[k];
    if(N >= k) dp[k] = N - k;
    else if(k == 1) dp[k] = 1;
    else if(k & 1) dp[k] = min(move(k+1), move(k-1)) + 1;
    else dp[k] = min(k-N, move(k/2));
    return dp[k];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    cout << move(K);
}