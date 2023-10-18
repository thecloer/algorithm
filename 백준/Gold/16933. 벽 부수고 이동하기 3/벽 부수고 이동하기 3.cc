#include <iostream>
#include <queue>
using namespace std;

struct xykd {int x, y, k, dist;};
char board[1000][1001];
int dist[1000][1000][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    int endX = N-1, endY = M-1;
    for(int i=0; i<N; i++) cin >> board[i];

    queue<xykd> Q;
    dist[0][0][0] = 1;
    Q.push({0, 0, 0, 1});
    while(!Q.empty()) {
        auto [x, y, k, d] = Q.front(); Q.pop();
        if(x == endX and y == endY) {
            cout << dist[x][y][k];
            return 0;
        }
        int nd = d + 1;
        bool wait = false;
        for(int i=4; i--;) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 or nx>endX or ny<0 or ny>endY) continue;
            int nk = board[nx][ny] == '1' ? k + 1 : k;
            if(nk > K) continue;
            if(dist[nx][ny][nk]) continue;
            if(board[nx][ny] == '1' and !(d & 1)) wait = true;
            else {
                dist[nx][ny][nk] = nd;
                Q.push({nx, ny, nk, nd});
            }
        }
        if(wait) Q.push({x, y, k, nd});
    }
    
    cout << -1;
}