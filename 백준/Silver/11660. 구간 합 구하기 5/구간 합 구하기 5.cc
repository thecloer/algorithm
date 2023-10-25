#include <iostream>
using namespace std;

int board[1025][1025];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
            board[i][j] += board[i][j-1] + board[i-1][j] - board[i-1][j-1];
        }
    }
    while(M--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << board[x2][y2] - board[x1-1][y2] - board[x2][y1-1] + board[x1-1][y1-1] << '\n';
    }
}