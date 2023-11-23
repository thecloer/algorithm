#include <iostream>
#include <algorithm>
using namespace std;

int getScore(int &base, int hitScore) {
    base = ((base << 1) | 1) << (hitScore - 1);
    int home = (base & 0b1111000) >> 3;
    base &= 0b111;
    int score = 0;
    while(home) {
        if(home & 1) score++;
        home >>= 1;
    }
    return score;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int hit[N][9];
    for(int i=0; i<N; i++)
        for(int j=0; j<9; j++)
            cin >> hit[i][j];
    
    int ans = 0;
    int batter[9];
    int order[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    do {
        for(int i=0; i<8; i++) batter[i] = order[i];
        batter[8] = batter[3];
        batter[3] = 0;
        
        int score = 0, turn = 0;
        for(int inning = 0; inning < N; inning++) {
            int out = 0, base = 0;
            while(out < 3) {
                if(not hit[inning][batter[turn]]) out++;
                else score += getScore(base, hit[inning][batter[turn]]);

                if(++turn > 8) turn %= 9;
            }
        }
        ans = max(ans, score);
    } while(next_permutation(order, order+8));
    cout << ans;
}