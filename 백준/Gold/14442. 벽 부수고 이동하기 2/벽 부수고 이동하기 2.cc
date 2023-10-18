#include <iostream>
#include <queue>
using namespace std;

struct xyk {int x, y, k;};
char board[1000][1001];
int dist[1000][1000][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int endX = N-1, endY = M-1;
    if(!(endX || endY)) {
        cout << 1;
        return 0;
    }
    for(int i=0; i<N; i++) 
        cin >> board[i];
    int ans = -1;
    queue<xyk> Q;
    dist[0][0][0] = 1;
    Q.push({0, 0, 0});
    while(!(Q.empty() || ans > 0)) {
        xyk cur = Q.front(); Q.pop();
        for(int d=4; d--;) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if(nx<0 || nx>endX || ny<0 || ny>endY) continue;
            if(nx == endX && ny == endY) {
                ans = dist[cur.x][cur.y][cur.k] + 1;
                break;
            }
            int nk = cur.k;
            if(board[nx][ny] == '1') {
                if(nk < K) nk++;
                else continue;
            }
            if(dist[nx][ny][nk]) continue;
            dist[nx][ny][nk] = dist[cur.x][cur.y][cur.k] + 1;
            Q.push({nx, ny, nk});
        }
    }
    if(ans > 0) cout << ans;
    else cout << -1;
}