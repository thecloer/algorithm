#include <iostream>
using namespace std;

int N;
int original[20][20];
int board[20][20];

void rotate90() {
    int tmp[N][N];
    for(int x=0; x<N; x++)
        for(int y=0; y<N; y++)
            tmp[y][N-1 - x] = board[x][y];
    for(int x=0; x<N; x++)
        for(int y=0; y<N; y++)
            board[x][y] = tmp[x][y];
}

void tilt(int dir) {
    while(dir--) rotate90();
    for(int line=0; line<N; line++) {
        int tmp[N];
        for(int i=0; i<N; i++) tmp[i] = 0;
        int top = 0;
        for(int x : board[line]) {
            if(x == 0) continue;
            if(tmp[top] == 0) tmp[top] = x;
            else if(tmp[top] == x) tmp[top++] *= 2;
            else tmp[++top] = x;
        }
        for(int i=0; i<N; i++) board[line][i] = tmp[i];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> original[i][j];

    int ans = 0;
    for(int tmp=0; tmp < (1 << 10); tmp++) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                board[i][j] = original[i][j];
        
        int cur = tmp;
        for(int t=5; t--;) {
            int dir = cur & 3;
            cur >>= 2;
            tilt(dir);
            
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    if(board[i][j] > ans) 
                        ans = board[i][j];
        }
    }
    cout << ans;
}