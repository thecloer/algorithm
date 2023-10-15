#include <iostream>
#include <queue>
using namespace std;

struct xyk {int x,y,k;};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {0, 1, 0, -1, 2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, W, H;
    cin >> K >> W >> H;
    int endX = H-1, endY = W-1;
    if(!(endX || endY)) {
        cout << 0;
        return 0;
    }
    int board[H][W];
    int dist[H][W][K+1];
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> board[i][j];
            for(int k=0; k<=K; k++)
                dist[i][j][k] = -1;
        }
    }
    queue<xyk> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 0;
    while(!Q.empty()) {
        xyk cur = Q.front(); Q.pop();
        int nxt = dist[cur.x][cur.y][cur.k] + 1;
        for(int d=12; d--;) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(nx<0 || nx>=H || ny<0 || ny>=W) continue;
            if(board[nx][ny] == 1) continue;
            int nk = d < 4 ? cur.k : cur.k + 1;
            if(nk > K) continue;
            if(dist[nx][ny][nk] != -1) continue;
            if(nx == endX && ny == endY) {
                cout << nxt;
                return 0;
            }
            dist[nx][ny][nk] = nxt;
            Q.push({nx, ny, nk});
        }
    }
    cout << -1;
}