#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int A[N], B[N], freqA[101]{}, freqB[101]{};
    for(int i=0; i<N; i++) { cin >> A[i]; freqA[A[i]]++; }
    for(int i=0; i<N; i++) { cin >> B[i]; freqB[B[i]]++; }
    for(int a=0, idx=0; idx<N; a++) {
        while(freqA[a]) {
            A[idx++] = a;
            freqA[a]--;
        }
    }
    for(int b=0, idx=0; idx<N; b++) {
        while(freqB[b]) {
            B[idx++] = b;
            freqB[b]--;
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++) ans += A[i] * B[N-1-i];
    cout << ans;
}