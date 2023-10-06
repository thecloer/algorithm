#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y; };
char board[1000][1001];
int times[1000][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int w, h;
        cin >> w >> h;
        queue<xy> Q;
        xy start;
        for(int i=0; i<h; i++) {
            cin >> board[i];
            for(int j=0; j<w; j++) {
                if(board[i][j] == '*') {
                    times[i][j] = 0;
                    Q.push({i, j});
                } else {
                    times[i][j] = -1;
                    if(board[i][j] == '@')
                        start = {i, j};
                }
            }
        }

        while(!Q.empty()) {
            xy cur = Q.front(); Q.pop();
            for(int d=4; d--;) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(board[nx][ny] == '#') continue;
                if(times[nx][ny] != -1) continue;
                times[nx][ny] = times[cur.x][cur.y] + 1;
                Q.push({nx, ny});
            }
        }

        int ans = 0;
        times[start.x][start.y] = 0;
        Q.push(start);
        while(!Q.empty()) {
            int x = Q.front().x, y = Q.front().y; Q.pop();
            int nxt = times[x][y] + 1;
            if(x == 0 || x == h-1 || y == 0 || y == w-1) {
                ans = nxt;
                break;
            }
            for(int d=4; d--;) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(board[nx][ny] == '#') continue;
                if(times[nx][ny] == -1 || nxt < times[nx][ny]) {
                    times[nx][ny] = nxt;
                    Q.push({nx, ny});
                }
            }
        }
        if(ans) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}