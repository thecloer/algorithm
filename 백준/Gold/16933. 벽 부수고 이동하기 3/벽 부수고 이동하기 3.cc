#include <iostream>
#include <queue>
using namespace std;

struct xyk {int x, y, k;};
char board[1000][1001];
bool vis[1000][1000][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    int endX = N-1, endY = M-1;
    for(int i=0; i<N; i++) cin >> board[i];

    queue<xyk> Q;
    Q.push({0, 0, 0});
    vis[0][0][0] = true;
    int ans = 1;
    while(!Q.empty()) {
        int size = Q.size();
        while(size--) {
            auto [x, y, k] = Q.front(); Q.pop();
            if(x == endX and y == endY) {
                cout << ans;
                return 0;
            }
            bool wait = false;
            for(int i=4; i--;) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0 or nx>endX or ny<0 or ny>endY) continue;
                int nk = board[nx][ny] == '1' ? k + 1 : k;
                if(nk > K or vis[nx][ny][nk]) continue;
                if(board[nx][ny] == '1' and !(ans & 1)) wait = true;
                else {
                    vis[nx][ny][nk] = true;
                    Q.push({nx, ny, nk});
                }
            }
            if(wait) Q.push({x, y, k});
        }
        ans++;
    }
    cout << -1;
}