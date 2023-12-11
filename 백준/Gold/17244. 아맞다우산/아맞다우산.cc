#include <iostream>
#include <queue>
using namespace std;
const int MAX_DIST = 2500;

struct xy {int x, y;};
int R, C, N=1, ans = MAX_DIST;
char board[50][50];
int dist[6][50][50];
bool vis[6];
xy stuff[6], E;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int idx) {
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            dist[idx][i][j] = MAX_DIST;
    const xy &start = stuff[idx];
    queue<xy> Q;
    Q.push(start);
    dist[idx][start.x][start.y] = 0;
    while(not Q.empty()) {
        const auto [x, y] = Q.front(); Q.pop();
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx<0 or nx>=R or ny<0 or ny>=C) continue;
            if(board[nx][ny] == '#') continue;
            if(dist[idx][nx][ny] <= dist[idx][x][y] + 1) continue;
            dist[idx][nx][ny] = dist[idx][x][y] + 1;
            Q.push({nx, ny});
        }
    }
}
void backTracking(int cur, int cnt, int sec) {
    if(sec + dist[cur][E.x][E.y] >= ans) return;
    if(cnt == N) {
        ans = sec + dist[cur][E.x][E.y];
        return;
    }
    for(int nxt=1; nxt<N; nxt++) {
        if(vis[nxt]) continue;
        vis[nxt] = true;
        backTracking(nxt, cnt+1, sec + dist[cur][stuff[nxt].x][stuff[nxt].y]);
        vis[nxt] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie();
    cin >> C >> R;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'S')
                stuff[0] = {i, j};
            else if(board[i][j] == 'E')
                E = {i, j};
            else if(board[i][j] == 'X')
                stuff[N++] = {i, j};
        }
    }
    for(int start=0; start<N; start++) bfs(start);
    backTracking(0, 1, 0);
    cout << ans;
}