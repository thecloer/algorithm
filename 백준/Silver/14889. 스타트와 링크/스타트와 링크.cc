#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[20][20];
int team[2][10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];
    
    bool mask[N];
    for(int i=0; i<N/2; i++) mask[i] = false;
    for(int i=N/2; i<N; i++) mask[i] = true;
    
    int ans = 40000;
    do {
        int idx[2] = {0, 0};
        for(int i=0; i<N; i++)
            team[mask[i]][idx[mask[i]]++] = i;
        
        int diff = 0;
        for(int t=0; t<2; t++)
            for(int i=0; i<N/2; i++)
                for(int j=0; j<N/2; j++)
                    if(t) diff += board[team[t][i]][team[t][j]];
                    else diff -= board[team[t][i]][team[t][j]];
        
        ans = min(ans, abs(diff));
    } while(next_permutation(mask, mask+N));
    cout << ans;
}