#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;

    int bitLimit = 2;
    while(N >= bitLimit) bitLimit <<= 1;
    int dist[bitLimit];
    for(int i=0; i<bitLimit; i++) dist[i] = -1;

    queue<int> Q;
    while(M--) {
        int x; cin >> x;
        dist[x] = 0;
        Q.push(x);
    }

    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int b = 1; b < bitLimit; (b <<= 1)) {
            int nx = x ^ b;
            if(nx >= bitLimit) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            Q.push(nx);
        }
    }

    int ans = 0;
    for(int i=0; i<=N; i++)
        if(dist[i] > ans) ans = dist[i];
    cout << ans;
}