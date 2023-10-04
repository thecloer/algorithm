#include <iostream>
#include <queue>
using namespace std;

struct xyz {int x, y, z;};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<xyz> Q;
int M, N, H, unripe, ans;
int box[100][100][100];

bool bfs() {
    int size = Q.size();
    if(size == 0) return false;
    while(size--) {
        xyz cur = Q.front(); Q.pop();
        for(int d=6; d--;) {
            int nx = cur.x + dx[d];
            if(nx<0 || nx>=H) continue;
            int ny = cur.y + dy[d];
            if(ny<0 || ny>=N) continue;
            int nz = cur.z + dz[d];
            if(nz<0 || nz>=M) continue;
            if(box[nx][ny][nz] != 0) continue;
            box[nx][ny][nz] = 1; 
            unripe--;
            Q.push({nx, ny, nz});
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;
    for(int h=0; h<H; h++) {
        for(int r=0; r<N; r++) {
            for(int c=0; c<M; c++) {
                cin >> box[h][r][c];
                if(box[h][r][c] == 0)
                    unripe++;
                else if(box[h][r][c] == 1)
                    Q.push({h, r, c});
            }
        }
    }
    while(unripe && bfs()) ans++;

    if(unripe > 0) ans = -1;
    cout << ans;
}