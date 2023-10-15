#include <iostream>
#include <queue>
using namespace std;

struct xy {int x,y;};
int N;
int board[100][100];
int vis[100][100];
int dist[100][100];
queue<xy> land[5001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int markLand() {
    int landCnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            queue<xy> Q;
            Q.push({i, j});
            vis[i][j] = ++landCnt;
            board[i][j] = landCnt;
            while(!Q.empty()) {
                xy cur = Q.front(); Q.pop();
                bool isBorder = false;
                for(int d=4; d--;) {
                    int nx = cur.x + dx[d], ny = cur.y + dy[d];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    if(vis[nx][ny]) continue;
                    if(board[nx][ny] == 0) {
                        isBorder = true;
                        continue;
                    }
                    vis[nx][ny] = landCnt;
                    board[nx][ny] = landCnt;
                    Q.push({nx, ny});
                }
                if(isBorder) land[landCnt].push(cur);
            }
        }
    }
    return landCnt;
}

int makeBridge(int landNum) {
    auto &Q = land[landNum];
    while(!Q.empty()) {
        xy cur = Q.front(); Q.pop();
        for(int d=4; d--;) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(vis[nx][ny] == landNum) continue;
            if(board[nx][ny] == 0) {
                vis[nx][ny] = landNum;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Q.push({nx, ny});
            }
            else return dist[cur.x][cur.y];
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    int landCnt = markLand();
    int ans = 200;
    for(int i=1; i<=landCnt; i++)
        ans = min(ans, makeBridge(i));
    cout << ans;
}