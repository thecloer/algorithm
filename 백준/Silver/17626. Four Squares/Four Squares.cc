#include <iostream>
using namespace std;
const int MAX = 4;
int min(int a, int b) {return a < b ? a : b;}
int dp[50001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    dp[1] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] = MAX;
        for(int j=1; j*j <= i; j++)
            dp[i] = min(dp[i], dp[i-j*j]);
        dp[i]++;
    }
    cout << dp[N];
}