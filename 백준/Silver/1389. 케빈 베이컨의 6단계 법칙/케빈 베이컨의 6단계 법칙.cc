#include <iostream>
#include <queue>
using namespace std;

bool connected[101][101];
int dist[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        connected[a][b] = connected[b][a] = true;
    }

    int mx = 500000, ans = 0;
    for(int start=1; start<=N; start++) {
        queue<int> Q;
        Q.push(start);
        dist[start][start] = 1;
        while(not Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int nx=1; nx<=N; nx++) {
                if(not connected[x][nx]) continue;
                if(dist[start][nx]) continue;
                dist[start][nx] = dist[start][x] + 1;
                Q.push(nx);
            }
        }
        int d = -N;
        for(int i=1; i<=N; i++) d += dist[start][i];
        if(d < mx) {
            mx = d;
            ans = start;
        }
    }
    cout << ans;
}