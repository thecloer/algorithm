#include <iostream>
using namespace std;

int dist[1000001];
int pre[1000001] {0, 1};

void move(int from, int to) {
    dist[to] = dist[from] + 1;
    pre[to] = from;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int x=2; x<=N; x++) {
        move(x-1, x);
        if(x % 3 == 0 and dist[x/3] + 1 < dist[x]) move(x/3, x);
        if((x & 1) == 0 and dist[x >> 1] + 1 < dist[x]) move(x >> 1, x);
    }
    cout << dist[N] << '\n';
    for(int x=N; (cout << x << ' ', x != pre[x]); x = pre[x]);
}