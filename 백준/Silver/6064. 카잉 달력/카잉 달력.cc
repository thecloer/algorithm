#include <iostream>
using namespace std;

int GCD(int a, int b) {return b ? GCD(b, a%b) : a;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int M, N, x, y; 
        cin >> M >> N >> x >> y;
        if(x == M) x = 0;
        if(y == N) y = 0;
        int lcm = M * N / GCD(M, N);
        int ans = -1;
        for(int k=x; k <= lcm; k += M) {
            if(k % N == y) {
                ans = k;
                break;
            }
        }
        if(ans == 0) ans = lcm;
        cout << ans << '\n';
    }
}