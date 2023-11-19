#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {int x, w;};
int n, maxDist, farV;
vector<edge> tree[10001];
void bfs(int start) {
    int dist[n+1];
    for(int &d:dist) d = 0;
    dist[start] = 1;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(auto [nx, w]:tree[x]) {
            if(dist[nx]) continue;
            dist[nx] = dist[x] + w;
            Q.push(nx);
        }
    }
    for(int i=1; i<=n; i++) {
        if(maxDist < dist[i]) {
            maxDist = dist[i];
            farV = i;
        }
    }
    maxDist--;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++) {
        int a, b, w; cin >> a >> b >> w;
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }
    bfs(1);
    bfs(farV);
    cout << maxDist;
}