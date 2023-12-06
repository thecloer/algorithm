#include <iostream>
using namespace std;

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
        if(not freq[len]) continue;
        if(ans < len * n) ans = len * n;
        n -= freq[len];
    }
    cout << ans;
}