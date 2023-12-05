#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parent[10001];
pair<int, pair<int, int>> edges[100000];

inline int fnd(int x) {
    return parent[x] ? (parent[x] = fnd(parent[x])) : x;
}
inline void uni(int a, int b) {
    parent[fnd(b)] = fnd(a);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }
    sort(edges, edges+E);

    int ans = 0;
    for(int i=0; i<E; i++) {
        const int &cost = edges[i].first;
        const auto &[a, b] = edges[i].second;
        if(fnd(a) == fnd(b)) continue;
        uni(a, b);
        ans += cost;
    }
    cout << ans;
}