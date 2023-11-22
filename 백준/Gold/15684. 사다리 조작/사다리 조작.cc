#include <iostream>
using namespace std;

int N, M, H;
bool connected[31][10];

bool play() {
    for(int col = 1; col < N; col++) {
        int me = col;
        for(int row = 1; row <= H; row++) {
            if(me > 1 and connected[row][me-1]) me--;
            else if(me < N and connected[row][me]) me++;
        }
        if(me != col) return false;
    }
    return true;
}

bool canConnect(int row, int col) {
    if(connected[row][col]) return false;
    if(col > 1 and connected[row][col-1]) return false;
    if(col < N-1 and connected[row][col+1]) return false;
    return true;
}

bool backTracking(int cursor, int n, int selected) {
    if(n == selected) return play();
    if(cursor < 0) return false;

    int col = 1 + cursor / H;
    int row = 1 + cursor % H;
    if(canConnect(row, col)) {
        connected[row][col] = true;
        if(backTracking(cursor-1, n, selected+1)) return true;
        connected[row][col] = false;
    }
    return backTracking(cursor-1, n, selected);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> H;
    while(M--) {
        int a, b; cin >> a >> b;
        connected[a][b] = true;
    }
    int ans = -1;
    for(int i=0; i<4; i++) {
        if(backTracking((N-1) * H - 1, i, 0)) {
            ans = i;
            break;
        }
    }
    cout << ans;
}