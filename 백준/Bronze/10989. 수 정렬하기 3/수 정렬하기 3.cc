#include <iostream>
using namespace std;

int freq[10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for(int i=1; i<10001; i++)
        while(freq[i]--)
            cout << i << '\n';
}