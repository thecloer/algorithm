#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {int v, w;};
int V, E, len, cnt;
bool vis[10001];
vector<edge> adj[10001];

bool cmp(edge &a, edge &b) {return a.w > b.w;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<edge, vector<edge>, decltype(&cmp)> pq(cmp);
    pq.push({1, 0});
    while(!pq.empty()) {
        const auto [x, w] = pq.top(); pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
        len += w;
        if(++cnt == V) break;
        for(const auto [nx, nw]:adj[x]) {
            if(vis[nx]) continue;
            pq.push({nx, nw});
        }
    }
    cout << len;
}