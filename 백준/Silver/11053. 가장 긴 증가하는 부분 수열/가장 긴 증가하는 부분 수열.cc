#include <iostream>
using namespace std;

int num[1001], len[1001];
int max(int a, int b) {return a > b ? a : b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<i; j++)
            if(num[j] < num[i])
                len[i] = max(len[i], len[j]);
        len[i]++;
    }
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, len[i]);
    cout << ans;
}