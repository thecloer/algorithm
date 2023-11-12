#include <iostream>
using namespace std;

int N, W, L;
int trucks[1001];
int bridge[101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W >> L;
    for(int i=0; i<N; i++) cin >> trucks[i];
    int sec = 0;
    int start = -1, cursor = 0, weight = 0;
    while(cursor < N || weight) {
        start = (start + 1) % (W+1);
        int end = (start + 1) % (W+1);
        if(bridge[end]) {
            weight -= bridge[end];
            bridge[end] = 0;
        }
        if(cursor < N && weight + trucks[cursor] <= L) {
            bridge[start] = trucks[cursor];
            weight += trucks[cursor++];
        }
        sec++;
    }
    cout << sec;
}