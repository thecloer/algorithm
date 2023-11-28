#include <iostream>
#include <string>
using namespace std;
int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str1, str2; cin >> str1 >> str2;
    int dp[str1.length()+1][str2.length()+1];
    for(int i=0; i<=str1.length(); i++) {
        for(int j=0; j<=str2.length(); j++) {
            if(i == 0 or j == 0) dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[str1.length()][str2.length()];
}