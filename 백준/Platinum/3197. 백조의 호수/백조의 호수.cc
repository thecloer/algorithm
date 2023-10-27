#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int R, C;
char board[1500][1501];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char mark[] = {'1', '2'};
queue<xy> Q[2];
queue<xy> B;

bool OOB(int x, int y) { return x<0 || x>=R || y<0 || y>=C; }
bool isBeach(int x, int y) {
    for(int dir=4; dir--;) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(board[nx][ny] == 'X') return true;
    }
    return false;
}
void melt() {
    for(int size = B.size(); size--;) {
        auto [x, y] = B.front(); B.pop();
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == 'X') {
                board[nx][ny] = '.';
                B.push({nx, ny});
            }
        }
    }
}
bool bfs(int k) {
    queue<xy> tmpQ;
    while(!Q[k].empty()) {
        auto [x, y] = Q[k].front(); Q[k].pop();
        bool wait = false;
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == mark[k]) continue;
            if(board[nx][ny] == mark[!k]) return true;
            if(board[nx][ny] == 'X') wait = true;
            else {
                board[nx][ny] = mark[k];
                Q[k].push({nx, ny});
            }
        }
        if(wait) tmpQ.push({x, y});
    }
    Q[k] = tmpQ;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++) cin >> board[i];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j] != 'X' && isBeach(i, j))
                B.push({i, j});
            if(board[i][j] == 'L') {
                board[i][j] = mark[Q[1].empty()];
                Q[Q[1].empty()].push({i, j});
            }
        }
    }

    int day = 0;
    while(!Q[0].empty()) {
        if(bfs(0)) break;
        if(bfs(1)) break;
        melt();
        day++;
    }
    cout << day;
}