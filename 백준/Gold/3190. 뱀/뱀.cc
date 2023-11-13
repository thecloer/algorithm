#include <iostream>
using namespace std;

struct command {char cmd; int time;};
int board[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) 
            board[i][j] = -1;
    while(K--) {
        int a, b; cin >> a >> b;
        board[a][b] = -2;
    }
    int L; cin >> L;
    command cmds[L];
    for(int i=0; i<L; i++) 
        cin >> cmds[i].time >> cmds[i].cmd;
    
    int sec = 0, dir = 0, len = 1, x = 1, y = 1, cmdIdx = 0;
    while(true) {
        board[x][y] = sec++;
        x += dx[dir]; y += dy[dir];
        if(board[x][y] == -2) len++;
        if(x<1 || x>N || y<1 || y>N || board[x][y] >= sec - len) break;
        if(cmdIdx < L && sec == cmds[cmdIdx].time)
            dir = (cmds[cmdIdx++].cmd == 'D' ? ++dir : --dir + 4 ) % 4;
    }
    cout << sec;
}