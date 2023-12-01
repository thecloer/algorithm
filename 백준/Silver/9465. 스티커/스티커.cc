#include <iostream>
using namespace std;

int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int sticker[2][n+1];
        for(int i=0; i<2; i++)
            for(int j=1; j<=n; j++)
                cin >> sticker[i][j];
        sticker[0][0] = sticker[1][0] = 0;
        
        int ans = 0;
        for(int i=2; i<=n; i++) {
            sticker[0][i] += max(sticker[1][i-2], sticker[1][i-1]);
            sticker[1][i] += max(sticker[0][i-2], sticker[0][i-1]);
        }
        cout << max(sticker[0][n], sticker[1][n]) << '\n';
    }
}
