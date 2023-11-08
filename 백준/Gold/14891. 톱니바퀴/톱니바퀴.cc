#include <iostream>
#include <string>
using namespace std;

int gears[5];
int directions[5];

void rotate(int gearIdx, int dir) {
    if(dir == 1) {
        int overflow = gears[gearIdx] & 1;
        gears[gearIdx] >>= 1;
        gears[gearIdx] += overflow << 7;
    } 
    else if(dir == -1) {
        int overflow = gears[gearIdx] >> 7;
        gears[gearIdx] <<= 1;
        gears[gearIdx] += overflow;
        gears[gearIdx] &= (1 << 8) - 1;
    }
}
bool checkPropagation(int leftIdx, int rightIdx) {
    int leftTooth = (gears[leftIdx] >> 5) & 1;
    int rightTooth = (gears[rightIdx] >> 1) & 1;
    return leftTooth xor rightTooth;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<5; i++) {
        string s; cin >> s;
        for(char c:s) 
            gears[i] = (gears[i] << 1) + (c - '0');
    }
    int k; cin >> k;
    while(k--) {
        int gearIdx, dir; cin >> gearIdx >> dir;
        for(int i=1; i<5; i++) directions[i] = 0;
        directions[gearIdx] = dir;
        int idx = gearIdx;
        while((idx < 4) and checkPropagation(idx, idx + 1)) {
            directions[idx + 1] = -directions[idx];
            idx++;
        }
        
        idx = gearIdx;
        while((idx > 1) and checkPropagation(idx - 1, idx)) {
            directions[idx - 1] = -directions[idx];
            idx--;
        }
        
        for(idx = 1; idx < 5; idx++)
            rotate(idx, directions[idx]);
    }

    int ans = 0;
    for(int i=1; i<5; i++)
        ans += ((gears[i] >> 7) << (i-1));
    cout << ans;
}
