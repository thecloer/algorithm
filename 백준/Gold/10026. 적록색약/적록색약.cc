#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char board[100][101];
bool vis[100][100];
queue<xy> Q;

void bfs(int x, int y) {
    char color = board[x][y];
    vis[x][y] = true;
    Q.push({x, y});
    while(!Q.empty()) {
        xy cur = Q.front(); Q.pop();
        for(int d=4; d--;) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(vis[nx][ny] || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int area() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            cnt++;
            bfs(i, j);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> board[i];
    
    cout << area() << ' ';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == 'G') board[i][j] = 'R';
            if(vis[i][j]) vis[i][j] = false;
        }
    }
    cout << area();
}