#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int numbers[N], operators[N-1];
    
    for(int i=0; i<N; i++) cin >> numbers[i];
    for(int i=0, oper=0; oper<4; oper++) {
        int cnt; cin >> cnt;
        while(cnt--) operators[i++] = oper;
    }

    int mx = -1000000000, mn = 1000000000;
    do {
        int res = numbers[0];
        for(int i=0; i<N-1; i++) {
            if(operators[i] == 0) res += numbers[i+1];
            else if(operators[i] == 1) res -= numbers[i+1];
            else if(operators[i] == 2) res *= numbers[i+1];
            else res /= numbers[i+1];
        }
        mx = max(mx, res);
        mn = min(mn, res);
    } while(next_permutation(operators, operators+N-1));

    cout << mx << '\n' << mn;
}