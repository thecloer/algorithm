#include <iostream>
// #include <unordered_set>
using namespace std;

struct xy {int x, y;};
int R, C, ans;
int board[21][21];
int vis[21][21];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void backTracking(int x, int y, int cnt, int bit) {
    bit |= 1 << board[x][y];
    // if(not vis[x][y].insert(bit).second) return;
    if(vis[x][y] == bit) return;
    vis[x][y] = bit;
    bool isLeaf = true;
    for(int dir = 4; dir--;) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx < 0 or nx >= R or ny < 0 or ny >= C) continue;
        if(bit & (1 << board[nx][ny])) continue;
        backTracking(nx, ny, cnt+1, bit);

        if(isLeaf) isLeaf = false;
    }
    if(isLeaf and cnt > ans) ans = cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            char c; cin >> c;
            board[i][j] = c - 'A';
        }
    }
    
    backTracking(0, 0, 1, 0);
    cout << ans;
}