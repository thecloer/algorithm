#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct xy {int x, y;};
int N, M, ans;
string board[600];
queue<xy> Q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> board[i];
        if(!Q.empty()) continue;
        for(int j=0; j<M; j++) 
            if(board[i][j] == 'I') Q.push({i, j});
    }
    while(!Q.empty()) {
        const auto [x, y] = Q.front(); Q.pop();
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(board[nx][ny] == 'X') continue;
            if(board[nx][ny] == 'P') ans++;
            board[nx][ny] = 'X';
            Q.push({nx, ny});
        }
    }
    if(ans) cout << ans;
    else cout << "TT";
}