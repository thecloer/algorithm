#include <iostream>
#include <vector>
using namespace std;

struct xy { int x, y; };
int n, ans;
vector<xy> queens;
bool cols[15];

bool checkDiagonal(int r, int c) {
    for(xy p:queens) 
        if(abs(r - p.x) == abs(c - p.y)) 
            return true;
    return false;
}

void backTracking(int r) {
    if(r == n) {
        ans++;
        return;
    }
    for(int c=0; c<n; c++) {
        if(cols[c]) continue;
        if(checkDiagonal(r, c)) continue;
        cols[c] = true;
        queens.push_back({r, c});
        backTracking(r+1);
        queens.pop_back();
        cols[c] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    backTracking(0);
    cout << ans;
}