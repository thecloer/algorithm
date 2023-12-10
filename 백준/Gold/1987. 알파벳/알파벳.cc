#include <iostream>
using namespace std;

struct xy {int x, y;};
int R, C, ans;
char board[21][21];
bool vis[26];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void backTracking(int x, int y, int cnt) {
    bool isLeaf = true;
    for(int dir = 4; dir--;) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx < 1 or nx > R or ny < 1 or ny > C) continue;
        if(vis[board[nx][ny] - 'A']) continue;
        vis[board[nx][ny] - 'A'] = true;
        backTracking(nx, ny, cnt+1);
        vis[board[nx][ny] - 'A'] = false;

        if(isLeaf) isLeaf = false;
    }
    if(isLeaf and cnt > ans) ans = cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            cin >> board[i][j];
    
    vis[board[1][1] - 'A'] = true;
    backTracking(1, 1, 1);
    cout << ans;
}