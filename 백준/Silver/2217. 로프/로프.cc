#include <iostream>
using namespace std;

inline int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, x; cin >> N;
    int freq[10001]{};
    for(int i=0; i<N; i++) {
        cin >> x;
        freq[x]++;
    }
    
    int ans = 0, acc = 0;
    for(int len=1; len<10001; len++) {
        if(not freq[len]) continue;
        ans = max(ans, len * (N - acc));
        acc += freq[len];
    }
    cout << ans;
}