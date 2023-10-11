#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char board[1000][1001];
int dist[1000][1000][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) cin >> board[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            dist[i][j][0] = dist[i][j][1] = -1;

    int endX = N-1, endY = M-1;
    queue<tuple<int, int, bool>> Q;
    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty()) {
        int x, y; bool broken;
        tie(x, y, broken) = Q.front(); 
        if(x == endX && y == endY) {
            cout << dist[x][y][broken];
            return 0;
        }
        Q.pop();
        int nxt = dist[x][y][broken] + 1;
        for(int d=4; d--;) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx<0 || nx >=N || ny<0 || ny>=M) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nxt;
                Q.push({nx, ny, broken});
            }
            if(board[nx][ny] == '1' && !broken && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nxt;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
}