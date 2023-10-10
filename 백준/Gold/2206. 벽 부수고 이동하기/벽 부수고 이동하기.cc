#include <iostream>
#include <queue>
using namespace std;

struct xy { int x, y; };
char board[1000][1001];
int dist[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    if(N * M == 1) { cout << 1; return 0; }
    for(int i=0; i<N; i++) cin >> board[i];

    queue<xy> Q, W;
    dist[0][0] = 1; 
    Q.push({0, 0});
    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y; Q.pop();
        for(int d=4; d--;) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx<0 || nx >=N || ny<0 || ny>= M) continue;
            if(dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                if(board[nx][ny] == '0')
                    Q.push({nx, ny});
                else
                    W.push({nx, ny});
            }
        }
    }
    int ans = dist[N-1][M-1];
    while(!W.empty()) {
        int x = W.front().x, y = W.front().y; W.pop();
        int nxt = dist[x][y] + 1;
        for(int d=4; d--;) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx<0 || nx >=N || ny<0 || ny>= M) continue;
            if(board[nx][ny] == '1') continue;
            if(dist[nx][ny] == 0 || nxt < dist[nx][ny]) {
                dist[nx][ny] = nxt;
                W.push({nx, ny});
            }
        }
    }
    if(ans == 0 || ans > dist[N-1][M-1])
        ans = dist[N-1][M-1];
    if(ans) cout << ans;
    else cout << -1;
}