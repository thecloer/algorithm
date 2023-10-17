#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;

    int bitLimit = 2;
    while(N >= bitLimit) bitLimit <<= 1;

    bool vis[bitLimit];
    for(int i=0; i<bitLimit; i++) vis[i] = false;

    queue<int> Q;
    while(M--) {
        int x; cin >> x;
        vis[x] = true;
        Q.push(x);
    }

    int ans = 0;
    while(!Q.empty()) {
        ans++;
        int size = Q.size();
        while(size--) {
            int x = Q.front(); Q.pop();
            for(int b = 1; b < bitLimit; (b <<= 1)) {
                int nx = x ^ b;
                if(nx > N) continue;
                if(vis[nx]) continue;
                vis[nx] = true;
                Q.push(nx);
            }
        }
    }
    cout << ans-1;
}