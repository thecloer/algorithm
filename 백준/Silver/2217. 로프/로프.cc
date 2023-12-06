#include <iostream>
using namespace std;

inline int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n;
    int freq[10001]{};
    for(int i=0; i<n; i++) {
        cin >> x;
        freq[x]++;
    }
    
    int ans = 0;
    for(int len=1; len<10001; len++) {
        if(freq[len] and ans < len * n) ans = len * n;
        n -= freq[len];
    }
    cout << ans;
}