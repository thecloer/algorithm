#include <iostream>
using namespace std;

int K;
int arr[13], selected[6];

void backTracking(int cur, int len) {
    if(len == 6) {
        for(int x : selected) 
            cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int nxt = cur + 1; nxt < K; nxt++){
        selected[len] = arr[nxt];
        backTracking(nxt, len+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(true) {
        cin >> K;
        if(!K) return 0;
        for(int i=0; i<K; i++) 
            cin >> arr[i];
        backTracking(-1, 0);
        cout << '\n';
    }
}