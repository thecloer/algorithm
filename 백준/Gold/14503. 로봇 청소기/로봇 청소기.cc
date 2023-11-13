#include <iostream>
using namespace std;

int N, M, x, y, d, cnt;
bool isWall[50][50];
bool isClean[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void move(int nx, int ny) { x = nx; y = ny; }
void clean() { isClean[x][y] = true; cnt++; }
bool isCleanAround() {
    for(int dir=4; dir--;) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(isWall[nx][ny]) continue;
        if(not isClean[nx][ny]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> x >> y >> d;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> isWall[i][j];
    while(true) {
        if(not isClean[x][y]) clean();
        if(isCleanAround()) {
            int backDir = (d + 2) % 4;
            int nx = x + dx[backDir];
            int ny = y + dy[backDir];
            if(isWall[nx][ny]) break;
            move(nx, ny);
        } else {
            int nx, ny;
            do {
                d = (--d + 4) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
            } while(isWall[nx][ny] or isClean[nx][ny]);
            move(nx, ny);
        }
    }
    cout << cnt;
}