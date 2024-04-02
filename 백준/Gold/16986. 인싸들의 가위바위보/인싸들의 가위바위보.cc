#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[10][10]; // 0: <, 1: =, 2: >
int hand[3][20]; // 0:나, 1: 경희, 2: 민호
int win[3], cursor[3], player[2];

inline int game() {
    return A[hand[player[0]][cursor[player[0]]++]][hand[player[1]][cursor[player[1]]++]];
}
inline bool canPlay() {
    if(player[0] == 0 and cursor[0] >= N) return false;
    if(player[1] == 0 and cursor[0] >= N) return false;
    if(cursor[player[0]] >= 20 or cursor[player[1]] >= 20) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> A[i][j];

    for(int i=1; i<3; i++)
        for(int j=0; j<20; j++)
            cin >> hand[i][j];
    
    if(K > N) {
        cout << 0;
        return 0;
    }
    
    for(int i=0; i<N; i++) hand[0][i] = i + 1;
    do {
        fill(win, win+3, 0);
        fill(cursor, cursor+3, 0);
        player[0] = 0; player[1] = 1;

        while(canPlay()) {
            int winnerIdx;
            switch (game()) {
            case 0: winnerIdx = 1; break;
            case 1: winnerIdx = player[0] > player[1] ? 0 : 1; break;
            case 2: winnerIdx = 0; break;
            }
            int winner = player[winnerIdx];
            if(++win[winner] == K) break;
            player[1] = 3 - winner - player[!winnerIdx]; // next player
            player[0] = winner;
        }
        if(win[0] == K) break;
    } while(next_permutation(hand[0], hand[0] + N));
    cout << (win[0] == K);
}