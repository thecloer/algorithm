#include <iostream>
#include <algorithm>
using namespace std;

int K;
int arr[13], mask[13];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(true) {
        cin >> K;
        if(!K) return 0;
        for(int i=0; i<K; i++) cin >> arr[i];
        for(int i=6; i<K; i++) mask[i] = 1;
        do {
            for(int i=0; i<K; i++)
                if(!mask[i]) cout << arr[i] << ' ';
            cout << '\n';
        } while(next_permutation(mask, mask + K));
        cout << '\n';
    }
}