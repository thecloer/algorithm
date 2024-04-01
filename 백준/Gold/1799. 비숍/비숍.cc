#include <iostream>
#include <vector>
using namespace std;

enum color {BLACK, WHITE};
struct xy {int x, y;};

int n, ans[2];
vector<xy> B[2];
bool diag[2][2][20]; // [color][0]: +, [color][1]: -

void backtracking(color c, int cur, int cnt) {
    if(cur == B[c].size()) {
        if(cnt > ans[c]) ans[c] = cnt;
        return;
    }
    if(cnt + B[c].size() - cur < ans[c]) return;

    if(diag[c][0][B[c][cur].x + B[c][cur].y] or diag[c][1][B[c][cur].x - B[c][cur].y + n]) {
        backtracking(c, cur+1, cnt);
        return;
    }

    diag[c][0][B[c][cur].x + B[c][cur].y] = diag[c][1][B[c][cur].x - B[c][cur].y + n] = true;
    backtracking(c, cur+1, cnt+1);
    diag[c][0][B[c][cur].x + B[c][cur].y] = diag[c][1][B[c][cur].x - B[c][cur].y + n] = false;
    backtracking(c, cur+1, cnt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    bool isB;
    for(int x=0; x<n; x++) {
        for(int y=0; y<n; y++) {
            cin >> isB;
            if(isB) B[(x ^ y) & 1].push_back({x, y});
        }
    }
    
    backtracking(BLACK, 0, 0);
    backtracking(WHITE, 0, 0);
    cout << ans[BLACK] + ans[WHITE];
}
