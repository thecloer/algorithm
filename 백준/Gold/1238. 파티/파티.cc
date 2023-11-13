#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_DIST = 1000001;

struct node {int v, w;};
int N, M, X;
vector<node> graph[1001];
int dist[1001];

bool cmp(int a, int b) { return dist[a] > dist[b]; }
int max(int a, int b) { return a > b ? a : b; }
int dijkstra(int from, int to) {
    for(int i=1; i<=N; i++) dist[i] = MAX_DIST;
    dist[from] = 0;
    priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);
    pq.push(from);
    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        for(const auto &[nx, w] : graph[x]) {
            if(dist[nx] <= dist[x] + w) continue;
            dist[nx] = dist[x] + w;
            pq.push(nx);
        }
    }
    return dist[to];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> X;
    while(M--) {
        int from, to, w; cin >> from >> to >> w;
        graph[from].push_back({to, w});
    }
    int ans = 0;
    for(int start = 1; start <= N; start++)
        ans = max(ans, dijkstra(start, X) + dijkstra(X, start));
    cout << ans;
}