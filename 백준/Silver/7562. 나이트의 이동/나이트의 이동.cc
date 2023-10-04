#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct xy { int x, y; };
int board[300][300];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n, x, y; 
        cin >> n;
        for(int i=0; i<n; i++) 
            fill(board[i], board[i]+n, -1);

        cin >> x >> y;
        board[x][y] = 0;
        queue<xy> Q;
        Q.push({x, y});

        cin >> x >> y;
        while(!Q.empty() && board[x][y] == -1) {
            xy cur = Q.front(); Q.pop();
            for(int d=8; d--;) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(board[nx][ny] != -1) continue;
                board[nx][ny] = board[cur.x][cur.y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << board[x][y] << '\n';
    }
}