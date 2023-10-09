#include <iostream>
#include <queue>
using namespace std;

struct xyz {int x, y, z;};
char building[30][30][31];
int times[30][30][30];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while(true) {
        int L, R, C; 
        cin >> L >> R >> C;
        if(!(L || R || C)) break;

        queue<xyz> Q;
        for(int i=0; i<L; i++) {
            for(int j=0; j<R; j++) {
                cin >> building[i][j];
                for(int k=0; k<C; k++) {
                    times[i][j][k] = 0;
                    if(building[i][j][k] == 'S') {
                        Q.push({i, j, k});
                        building[i][j][k] = '#';
                    }
                }
            }
        }
        int ans = -1;
        while(!Q.empty() && ans < 0) {
            xyz cur = Q.front(); Q.pop();
            for(int d=6; d--;) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                int nz = cur.z + dz[d];
                int nxt = times[cur.x][cur.y][cur.z] + 1;
                if(nx<0 || nx>=L || ny<0 || ny>=R || nz<0 || nz>=C) continue;
                if(building[nx][ny][nz] == '#') continue;
                if(building[nx][ny][nz] == 'E') {
                    ans = nxt;
                    break;
                }
                building[nx][ny][nz] = '#';
                times[nx][ny][nz] = nxt;
                Q.push({nx, ny, nz});
            }
        }
        if(ans < 0) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
}