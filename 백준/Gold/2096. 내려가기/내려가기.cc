#include <iostream>
using namespace std;

int input[3];
int dp[2][2][3];

inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int calc(bool isMax, int a, int b) {return isMax ? max(a, b) : min(a, b);}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n;
    while(n--) {
        bool cur = n & 1;
        bool before = !cur;
        for(int i=0; i<3; i++) {
            cin >> x;
            for(int isMax=0; isMax<2; isMax++) {
                dp[isMax][cur][i] = dp[isMax][before][i];
                if(i > 0) dp[isMax][cur][i] = calc(isMax, dp[isMax][cur][i], dp[isMax][before][i - 1]);
                if(i < 2) dp[isMax][cur][i] = calc(isMax, dp[isMax][cur][i], dp[isMax][before][i + 1]);
                dp[isMax][cur][i] += x;
            }
        }
    }
    for(int isMax=0; isMax<2; isMax++)
        for(int i=1; i<3; i++)
            dp[isMax][0][0] = calc(isMax, dp[isMax][0][0], dp[isMax][0][i]);
    cout << dp[1][0][0] << ' ' << dp[0][0][0];
}