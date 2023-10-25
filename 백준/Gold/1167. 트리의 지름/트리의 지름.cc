#include <iostream>
#include <vector>
using namespace std;

struct link {int v, w;};
int V, farV, maxDist;
bool isLeaf;
bool vis[100001];
vector<link> adj[100001];

void dfs(int cur, int dist) {
    vis[cur] = true;
    isLeaf = true;
    for(auto &nxt: adj[cur]) {
        if(vis[nxt.v]) continue;
        if(isLeaf) isLeaf = false;
        dfs(nxt.v, dist + nxt.w);
    }
    if(isLeaf && dist > maxDist) {
        maxDist = dist;
        farV = cur;
    }
    vis[cur] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i=0; i<V; i++) {
        int x; cin >> x;
        while(true) {
            int y; cin >> y;
            if(y == -1) break;
            int w; cin >> w;
            adj[x].push_back({y, w});
        }
    }
    dfs(1, 0);
    dfs(farV, 0);
    cout << maxDist;
}