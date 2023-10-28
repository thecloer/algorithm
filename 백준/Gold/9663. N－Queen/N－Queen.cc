#include <iostream>
using namespace std;

struct xy { int x, y; };
int n, ans;
bool cols[14];
bool diagonals[2][29];

bool checkDiagonals(int r, int c) {
    for(int i=0; i<n; i++)
        if(diagonals[i][0] || diagonals[i][1])
            return true;
    return false;
}
void backTracking(int r) {
    if(r == n) {
        ans++;
        return;
    }
    for(int c=0; c<n; c++) {
        if(cols[c] || diagonals[0][r+c] || diagonals[1][r-c+n-1]) continue;
        cols[c] = true;
        diagonals[0][r+c] = true;
        diagonals[1][r-c+n-1] = true;
        backTracking(r+1);
        diagonals[0][r+c] = false;
        diagonals[1][r-c+n-1] = false;
        cols[c] = false;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    backTracking(0);
    cout << ans;
}