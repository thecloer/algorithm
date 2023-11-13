#include <iostream>
using namespace std;
const int MID = 1000000;

bool arr[2 * MID + 1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr[MID + x] = true;
    }
    for(int i=0, cnt=0; cnt!=n && i<2*MID+1; i++) {
        if(arr[i]) {
            cnt++;
            cout << i - MID << '\n';
        }
    }
}