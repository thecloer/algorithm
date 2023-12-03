#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_DIST = 2e8;

struct vw {int v, w;};
int N, E;
int dist[801];
vector<vw> adj[801];

int min(int a, int b) {return a < b ? a : b;}
bool cmp(vw &a, vw &b) {return a.w > b.w;}
void dijkstra(int start) {
    for(int i=1; i<=N; i++) dist[i] = MAX_DIST;
    dist[start] = 0;
    priority_queue<vw, vector<vw>, decltype(&cmp)> Q(cmp);
    Q.push({start, 0});
    while(not Q.empty()) {
        const auto [x, d] = Q.top(); Q.pop();
        for(const auto [nx, w]:adj[x]) {
            if(dist[nx] > dist[x] + w) {
                dist[nx] = dist[x] + w;
                Q.push({nx, dist[nx]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> E;
    for(int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int v1, v2; cin >> v1 >> v2;
    dijkstra(1);
    int path1 = dist[v1];
    int path2 = dist[v2];

    dijkstra(N);
    path1 += dist[v2];
    path2 += dist[v1];

    dijkstra(v1);
    int ans = dist[v2] + min(path1, path2);

    cout << (ans < MAX_DIST ? ans : -1);
}