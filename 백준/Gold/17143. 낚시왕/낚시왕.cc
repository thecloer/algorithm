#include <iostream>
using namespace std;
const int SPEED = 0, DIR = 1, SIZE = 2;

int R, C, M;
int board[101][101];
int tmp[101][101];
int shark[10001][3];

int fish(int loc) {
    for(int depth=1; depth<=R; depth++) {
        if(board[depth][loc]) {
            int idx = board[depth][loc];
            board[depth][loc] = 0;
            return shark[idx][SIZE];
        }
    }
    return 0;
}
void moveShark() {
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            tmp[i][j] = 0;
    
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(board[i][j] == 0) continue;
            int x = i, y = j, idx = board[i][j];
            int &pos = shark[idx][DIR] < 3 ? x : y;
            int high = shark[idx][DIR] < 3 ? R : C;
            int sign = shark[idx][DIR] & 0b10 ? 1 : -1; // DR: 1, UL: -1
            pos += sign * shark[idx][SPEED];
            bool isOpposite = false;
            while(pos < 1 or pos > high) {
                if(pos < 1) pos = 2 - pos;
                else pos = 2*high - pos;
                isOpposite = !isOpposite;
            }
            if(isOpposite) {
                if(shark[idx][DIR] & 1) shark[idx][DIR]++;
                else shark[idx][DIR]--;
            }
            if(shark[tmp[x][y]][SIZE] < shark[idx][SIZE]) tmp[x][y] = idx;
        }
    }

    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            board[i][j] = tmp[i][j];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    for(int i=1; i<=M; i++) {
        int r, c; cin >> r >> c;
        board[r][c] = i;
        for(int info=0; info<3; info++)
            cin >> shark[i][info];
    }
    
    long long ans = 0;
    for(int loc=1; loc<=C; loc++) {
        ans += fish(loc);
        moveShark();
    }
    cout << ans;
}