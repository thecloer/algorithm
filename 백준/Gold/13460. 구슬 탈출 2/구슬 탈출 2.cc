#include <iostream>
using namespace std;

struct xy {int x, y;};
int N, M, n, m;
char original[10][10];
char board[10][10];
char tmp[10][10];
xy red, blue;

void copyToBoard() {
    n = N; m = M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(original[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '#';
            }
            else if(original[i][j] == 'B') {
                blue = {i, j};
                board[i][j] = '#';
            }
            else board[i][j] = original[i][j];
        }
    }
}
void swap(int &a, int &b) {
    int c = a; a = b; b = c;
}
void rotate90() {
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            tmp[x][y] = board[x][y];
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            board[y][n-1-x] = tmp[x][y];
    swap(blue.x, blue.y);
    blue.y = n-1-blue.y;
    swap(red.x, red.y);
    red.y = n-1-red.y;
    swap(n, m);
}
bool isNextWall(xy &ball) {return board[ball.x][ball.y - 1] == '#';}
bool isNextEmpty(xy &ball) {return board[ball.x][ball.y - 1] == '.';}
bool isNextHole(xy &ball) {return board[ball.x][ball.y - 1] == 'O';}
void move(xy &ball) {
    board[ball.x][ball.y] = '.';
    board[ball.x][--ball.y] = '#';
}
void out(xy &ball) {
    board[ball.x][ball.y] = '.';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> original[i][j];
    
    int ans = -1;
    for(int brute = 0; brute < (1<<20); brute++) {
        copyToBoard();
        int cur = brute;
        for(int t = 1; t <= 10; t++) {
            int rot = cur & 3;
            cur >>= 2;
            for(int i = 0; i < rot; i++) rotate90();
            bool isRedOut = false, isBlueOut = false;
            while(true) {
                if(!isBlueOut) {
                    if(isNextEmpty(blue)) move(blue);
                    else if(isNextHole(blue)) {
                        out(blue);
                        isBlueOut = true;
                    }
                }
                if(!isRedOut) {
                    if(isNextEmpty(red)) move(red);
                    else if(isNextHole(red)) {
                        out(red);
                        isRedOut = true;
                    }
                }
                if(isNextWall(red) && isNextWall(blue)) break;
                if(isRedOut && isNextWall(blue)) break;
                if(isNextWall(red) && isBlueOut) break;
                if(isRedOut && isBlueOut) break;
            }
            if(isRedOut && !isBlueOut && (ans == -1 || ans > t))
                    ans = t;
            if(isRedOut || isBlueOut) break;
        }
    }
    cout << ans;
}