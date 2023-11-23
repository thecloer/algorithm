#include <iostream>
using namespace std;

bool board[101][101];
int curve[1024];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while(N--) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        board[x][y] = true;
        int curveSize = 1;
        curve[0] = d;
        while(g--)
            for(int i=curveSize-1; i>=0; i--)
                curve[curveSize++] = (curve[i] + 1) & 3;
        for(int i=0; i<curveSize; i++) {
            int dir = curve[i];
            if(dir == 0) x++;
            else if(dir == 1) y--;
            else if(dir == 2) x--;
            else y++;
            board[x][y] = true;
        }
    }

    int ans = 0;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            if(board[i][j] && board[i+1][j] 
            && board[i][j+1] && board[i+1][j+1]) ans++;
    cout << ans;
}