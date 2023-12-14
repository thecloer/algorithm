#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie();
    char color[2] {'B', 'W'};
    int N, M; cin >> N >> M;
    char board[N][M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) 
            cin >> board[i][j];

    int ans = N * M;
    for(int x=0; x<=N-8; x++) {
        for(int y=0; y<=M-8; y++) {
            for(int i=0, cnt=0; i<2; i++, cnt=0) {
                for(int dx=0; dx<8; dx++) {
                    for(int dy=0; dy<8; dy++) {
                        if(board[x+dx][y+dy] != color[i]) cnt++;
                        i ^= 1;
                    }
                    i ^= 1;
                }
                if(cnt < ans) ans = cnt;
            }
        }
    }
    cout << ans;
}