#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct xw {int x, w;};
int V, E;
bool vis[10001];
vector<xw> adj[10001];

bool cmp(xw &a, xw &b) {return a.w > b.w;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<xw, vector<xw>, decltype(&cmp)> pq(cmp);
    pq.push({1, 0});

    int len = 0, cnt = 0;
    while(!pq.empty()) {
        const auto [x, w] = pq.top(); pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
        len += w;
        if(++cnt == V) break;
        for(const auto [nx, nw]:adj[x])
            if(not vis[nx]) 
                pq.push({nx, nw});
    }
    cout << len;
}