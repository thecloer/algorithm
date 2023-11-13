#include <iostream>
#include <queue>
using namespace std;

struct command {char cmd; int time;};
int N, K, sec, dir, len = 1, x = 1, y = 1;
int board[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<command> cmds;

void move() {
    x += dx[dir]; y += dy[dir];
    if(board[x][y] == -2) len++;
}
bool gameOver() {
    return x<1 || x>N || y<1 || y>N || board[x][y] >= sec - len;
}
void turn(char cmd) {
    dir = (cmd == 'D' ? ++dir : --dir + 4 ) % 4;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            board[i][j] = -1;
    cin >> K;
    while(K--) {
        int a, b; cin >> a >> b;
        board[a][b] = -2;
    }
    cin >> K;
    while(K--) {
        int X; char C; cin >> X >> C;
        cmds.push({C, X});
    }
    while(true) {
        board[x][y] = sec++;
        move();
        if(gameOver()) break;
        if(!cmds.empty() && sec == cmds.front().time) {
            turn(cmds.front().cmd);
            cmds.pop();
        }
    }
    cout << sec;
}