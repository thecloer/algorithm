#include <iostream>
#include <queue>
using namespace std;

bool vis[500001][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    queue<int> Q;
    vis[N][0] = true;
    Q.push(N);
    for(int sis=K, time=0; sis<500001; sis += ++time) {
        if(vis[sis][time & 1]) {
            cout << time;
            return 0;
        }
        int size = Q.size();
        while(size--) {
            int x = Q.front(); Q.pop();
            for(int nx : {2*x, x+1, x-1}) {
                if(nx<0 || nx>500000) continue;
                if(vis[nx][!(time & 1)]) continue;
                vis[nx][!(time & 1)] = true;
                Q.push(nx);
            }
        }
    }
    cout << -1;
}