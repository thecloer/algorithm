#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    queue<xy> Q;
    while(T--) {
        int M, N, K; cin >> M >> N >> K;
        int m[50][50] = {};
        xy v[K];
        while(K--) {
            int x, y; cin >> x >> y;
            m[x][y] = 1;
            v[K] = {x, y};
        }
        int ans = 0;
        for(xy p:v) {
            if(m[p.x][p.y] == 0) continue;
            ans++;
            Q.push(p);
            while(!Q.empty()) {
                xy cur = Q.front(); Q.pop();
                for(int d=4; d--;) {
                    int nx = cur.x + dx[d], ny = cur.y + dy[d];
                    if(nx<0 || nx>=M || ny<0 || ny>=N) continue;
                    if(m[nx][ny] == 0) continue;
                    m[nx][ny] = 0;
                    Q.push({nx, ny});
                }
            }
        }
        cout << ans << '\n';
    }
}