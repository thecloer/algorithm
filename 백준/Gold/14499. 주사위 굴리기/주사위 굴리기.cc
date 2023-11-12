#include <iostream>
using namespace std;
const int TOP = 1, BOTTOM = 6;

int N, M, x, y, K;
int board[20][20];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int dice[7];
int diceFlow[][4] = {
    {},
    {4, 6, 3, 1}, // 동 1
    {1, 3, 6, 4}, // 서 2
    {6, 5, 1, 2}, // 북 3
    {2, 1, 5, 6} // 남 4
};
bool moveDice(int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if(nx<0 || nx>=N || ny<0 || ny>=M) return false;
    x = nx; y = ny;
    return true;
}
void rollDice(int dir) {
    int tmp = dice[diceFlow[dir][3]];
    for(int i=3; i>0; i--)
        dice[diceFlow[dir][i]] = dice[diceFlow[dir][i-1]];
    dice[diceFlow[dir][0]] = tmp;
}
void copyBottom() {
    if(board[x][y]) {
        dice[BOTTOM] = board[x][y];
        board[x][y] = 0;
    } else board[x][y] = dice[BOTTOM];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> board[i][j];
    while(K--) {
        int dir; cin >> dir;
        if(not moveDice(dir)) continue;
        rollDice(dir);
        copyBottom();
        cout << dice[TOP] << '\n';
    }
}