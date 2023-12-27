#include <iostream>
using namespace std;

int R, C, T;
int room[50][50];
int tmp[50][50];
int airPurifierBottom;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
enum Wise { CLOCKWISE, COUNTERCLOCKWISE };
int wise[2][4] = {
    { 1, 0, 3, 2 }, // R, D, L, U
    { 1, 2, 3, 0 } // R, U, L, D
}; 

inline bool OOB(int x, int y) {return x<0 or x>=R or y<0 or y>=C;}
void diffuse() {
    for(int x = 0; x < R; x++)
        for(int y = 0; y < C; y++)
            tmp[x][y] = 0;

    for(int x = 0; x < R; x++) {
        for(int y = 0; y < C; y++) {
            if(room[x][y] == 0) continue;
            if(room[x][y] == -1) {
                tmp[x][y] = -1;
                continue;
            }
            int cnt = 0, amount = room[x][y] / 5;
            for(int dir = 4; dir--;) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(OOB(nx, ny)) continue;
                if(room[nx][ny] == -1) continue;
                tmp[nx][ny] += amount;
                cnt++;
            }
            tmp[x][y] += room[x][y] - cnt * amount;
        }
    }

    for(int x = 0; x < R; x++)
        for(int y = 0; y < C; y++)
            room[x][y] = tmp[x][y];
}
void circulate(Wise w, int x, int y, int dir, int prevVal) {
    if(room[x][y] == -1) return;

    int val = room[x][y];
    room[x][y] = prevVal;
    int nx = x + dx[wise[w][dir]];
    int ny = y + dy[wise[w][dir]];
    if(OOB(nx, ny)) {
        dir++;
        nx = x + dx[wise[w][dir]];
        ny = y + dy[wise[w][dir]];
    }
    circulate(w, nx, ny, dir, val);
}
void purify() {
    circulate(COUNTERCLOCKWISE, airPurifierBottom - 1, 1, 0, 0);
    circulate(CLOCKWISE, airPurifierBottom, 1, 0, 0);
}
int getPollution() {
    int pollution = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(room[i][j] > 0)
                pollution += room[i][j];
    return pollution;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> room[i][j];
            if(room[i][j] == -1)
                airPurifierBottom = i;
        }
    }
    while(T--) {
        diffuse();
        purify();
    }
    cout << getPollution();
}