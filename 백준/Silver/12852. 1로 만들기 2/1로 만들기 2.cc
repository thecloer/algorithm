#include <iostream>
#include <queue>
using namespace std;

int dist[1000001];
int pre[1000001];
queue<pair<int,int>> Q;

void enqueue(int x, int nx, int nd) {
    if(dist[nx] and dist[nx] <= nd) return;
    Q.push({nx, nd});
    dist[nx] = nd;
    pre[nx] = x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    Q.push({N, 0});
    pre[N] = N;
    while(not Q.empty()) {
        const auto [x, d] = Q.front(); Q.pop();
        int nd = d + 1;
        if(x % 3 == 0) enqueue(x, x / 3, nd);
        if((x & 1) == 0) enqueue(x, x / 2, nd);
        if(x > 1) enqueue(x, x -1, nd);
    }
    cout << dist[1] << '\n';
    int path[dist[1]+1];
    path[0] = N;
    for(int x=1, i=dist[1]; pre[x] != x; x = pre[x]) path[i--] = x;
    for(int x:path) cout << x << ' ';
}