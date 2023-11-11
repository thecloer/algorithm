#include <iostream>
using namespace std;

int freq[2000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int x; cin >> x;
        freq[x + 1000000]++;
    }
    for(int i=0, j=0; i<2000001 and j<N; i++) {
        if(!freq[i]) continue;
        for(int k=0; k<freq[i]; k++)
            cout << i - 1000000 << '\n';
        j += freq[i];
    }
}