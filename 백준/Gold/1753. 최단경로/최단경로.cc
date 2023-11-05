#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge { int v, w; };
int V, E, start;
vector<edge> adj[20001];
int dist[20001];

bool cmp(int a, int b) { return dist[a] > dist[b]; }
priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> start;
    while(E--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for(int i=1; i<=V; i++) dist[i] = -1;
    dist[start] = 0;
    pq.push(start);
    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        for(const auto &[nx, w] : adj[x]) {
            if(dist[nx] == -1 || dist[nx] > dist[x] + w) {
                dist[nx] = dist[x] + w;
                pq.push(nx);
            }
        }
    }
    for(int i=1; i<=V; i++) {
        if(dist[i] == -1) cout << "INF";
        else cout << dist[i];
        cout << '\n';
    }
}