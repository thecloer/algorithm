#include <iostream>
#include <queue>
using namespace std;

bool adj[101][101];
int dist[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(dist[i][j] == 0)
                dist[i][j] = -1;
    for(int p=1; p<=N; p++) {
        dist[p][p] = 0;
        queue<int> Q;
        Q.push(p);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int nx = 1; nx <= N; nx++) {
                if(!adj[x][nx]) continue;
                if(dist[p][nx] != -1) continue;
                dist[p][nx] = dist[p][x] + 1;
                Q.push(nx);
            }
        }
    }
    int ans = 0, mx = 101;
    for(int i=1; i<=N; i++) {
        int len = 0;
        for(int j=1; j<=N; j++) 
            len += dist[i][j];
        if(mx > len) {
            mx = len;
            ans = i;
        }
    }
    cout << ans;
}