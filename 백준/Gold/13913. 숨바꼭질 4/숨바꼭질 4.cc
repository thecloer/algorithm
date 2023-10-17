#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dist[1000001];
int from[1000001];

void path(int dest) {
    if(dest != N) path(from[dest]);
    cout << dest << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int &p:from) p = -1;

    queue<int> Q;
    Q.push(N);
    dist[N] = 1;
    from[N] = N;
    while(!(Q.empty() || dist[K])) {
        int x = Q.front(); Q.pop();
        for(int nx:{2*x, x+1, x-1}) {
            if(nx<0 || nx>100000) continue;
            if(dist[nx]) continue;
            dist[nx] = dist[x] + 1;
            from[nx] = x;
            Q.push(nx);
        }
    }
    cout << dist[K] - 1 << '\n';
    path(K);
}