#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_DIST = 1e9;

struct xw {int x, w;};
vector<xw> adj[1001];
bool vis[1001];
int dist[1001];

bool cmp(int a, int b) { return dist[a] > dist[b]; }
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    while(M--) {
        int from, to, w; 
        cin >> from >> to >> w;
        adj[from].push_back({to, w});
    }

    int src, dest; cin >> src >> dest;  
    for(int i=1; i<=N; i++) dist[i] = MAX_DIST;
    priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);
    dist[src] = 0;
    pq.push(src);
    while(not (pq.empty() or vis[dest])) {
        const int x = pq.top(); pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(const auto &[nx, nw]:adj[x]) {
            if(vis[nx] || dist[nx] <= dist[x] + nw) continue;
            dist[nx] = dist[x] + nw;
            pq.push(nx);
        }
    }
    cout << dist[dest];
}