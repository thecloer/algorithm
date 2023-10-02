#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dp[100001];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    if(N == K) {
        cout << 0;
        return 0;
    }
    Q.push(N);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int nx: { x-1, x+1, 2*x }) {
            if(nx < 0 || nx > 100000) continue;
            if(nx == N || dp[nx] > 0) continue;
            if(nx == K) {
                cout << dp[x] + 1;
                return 0;
            }
            dp[nx] = dp[x] + 1;
            Q.push(nx);
        }
    }
}