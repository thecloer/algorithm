#include <iostream>
using namespace std;

long long dp[101] = {0, 1, 1, 1, 2, 2};

long long getLength(int n) {
    if(dp[n]) return dp[n];
    return dp[n] = getLength(n-1) + getLength(n-5);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
        int n; cin >> n;
        cout << getLength(n) << '\n';
	}
}