#include <iostream>
#include <queue>
using namespace std;

int dist[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K; cin >> N >> K;
    queue<int> Q;
    Q.push(N);
    dist[N] = 1;
    while(dist[K] == 0) {
        int x = Q.front(); Q.pop();
        for(int nx=2*x; nx<100001; nx *= 2) {
            if(dist[nx]) break;
            dist[nx] = dist[x];
            Q.push(nx);
        }
        for(int nx:{x-1, x+1}) {
            if(nx<0 || nx>100000) continue;
            if(dist[nx]) continue;
            dist[nx] = dist[x] + 1;
            Q.push(nx);
        }
    }
    cout << dist[K] - 1;
}