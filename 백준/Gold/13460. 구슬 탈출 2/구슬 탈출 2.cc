#include <iostream>
#include <queue>
using namespace std;

struct loc {int rx, ry, bx, by;};
int N, M;
char board[10][10];
bool vis[10][10][10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char nextMove(int x, int y, int dir) {
    return board[x + dx[dir]][y + dy[dir]];
}
void move(int &x, int &y, int dir) {
    x += dx[dir]; y += dy[dir];
}

int bfs(const loc &start) {
    int cnt = 0;
    queue<loc> Q;
    Q.push(start);
    vis[start.rx][start.ry][start.bx][start.by] = true;
    while(!Q.empty()) {
        if(++cnt > 10) return -1;
        for(int size = Q.size(); size--;) {
            auto [rx, ry, bx, by] = Q.front(); Q.pop();
            for(int dir=4; dir--;) {
                // 파란공 이동
                int nbx = bx, nby = by;
                while(nextMove(nbx, nby, dir) == '.') move(nbx, nby, dir);
                if(nextMove(nbx, nby, dir) == 'O') continue;
                
                // 빨간공 이동
                int nrx = rx, nry = ry;
                while(nextMove(nrx, nry, dir) == '.') move(nrx, nry, dir);
                if(nextMove(nrx, nry, dir) == 'O') return cnt;

                // 두 공이 겹친 경우 늦게 출발한 공 한칸 뒤로 이동
                if((nrx == nbx) and (nry == nby)) {
                    if(dir == 0) // 남
                        rx < bx ? nrx-- : nbx--;
                    else if(dir == 1) // 동
                        ry < by ? nry-- : nby--;
                    else if(dir == 2) // 북
                        rx > bx ? nrx++ : nbx++;
                    else // 서
                        ry > by ? nry++ : nby++;
                }

                if(vis[nrx][nry][nbx][nby]) continue;
                vis[nrx][nry][nbx][nby] = true;
                Q.push({nrx, nry, nbx, nby});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    loc start;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                board[i][j] = '.';
                start.rx = i;
                start.ry = j;
            }
            else if(board[i][j] == 'B') {
                board[i][j] = '.';
                start.bx = i;
                start.by = j;
            }
        }
    };
    cout << bfs(start);
}