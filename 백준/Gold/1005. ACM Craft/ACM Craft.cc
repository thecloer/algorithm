#include <iostream>
#include <vector>
using namespace std;

int delay[1001];
int dp[1001];
vector<int> previous[1001];

int max(int a, int b) { return a > b ? a : b; }
int getTime(int root) {
    if(dp[root]) return dp[root];
    int mx = 0;
    while(!previous[root].empty()) {
        int pre = previous[root].back();
        previous[root].pop_back();
        mx = max(mx, getTime(pre));
    }
    return dp[root] = delay[root] + mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        for(int i=1; i<=N; i++) {
            cin >> delay[i];
            dp[i] = 0;
            previous[i].clear();
        }
        while(K--) {
            int x, y; cin >> x >> y;
            previous[y].push_back(x);
        }
        int root; cin >> root;
        cout << getTime(root) << '\n';
    }
}