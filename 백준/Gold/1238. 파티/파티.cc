#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_DIST = 100000;

struct xd {int x, d;};
int N, M, X;
vector<xd> adj[1001];
int dist[1001];

bool cmp(const xd &a, const xd &b) { return a.d > b.d; }
int max(int a, int b) { return a > b ? a : b; }
int dijkstra(int from, int to) {
    priority_queue<xd, vector<xd>, decltype(&cmp)> pq(cmp);
    for(int i=1; i<=N; i++) dist[i] = MAX_DIST;
    dist[from] = 0;
    pq.push({from, 0});
    while(!pq.empty()) {
        const auto [x, d] = pq.top(); pq.pop();
        if(d > dist[x]) continue;
        for(const auto &[nx, nw] : adj[x]) {
            if(dist[nx] <= dist[x] + nw) continue;
            dist[nx] = dist[x] + nw;
            pq.push({nx, dist[nx]});
        }
    }
    return dist[to];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> X;
    while(M--) {
        int from, to, w; cin >> from >> to >> w;
        adj[from].push_back({to, w});
    }
    int ans = 0;
    for(int start = 1; start <= N; start++)
        ans = max(ans, dijkstra(start, X) + dijkstra(X, start));
    cout << ans;
}