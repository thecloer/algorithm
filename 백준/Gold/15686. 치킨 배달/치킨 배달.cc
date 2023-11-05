#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int abs(int a) { return a < 0 ? -a : a; };
inline int min(int a, int b) { return a < b ? a : b; };

struct xy {int x, y;};
int N, M, ans = 250000;
int board[50][50];
vector<xy> house, chicken, selected;

void backTracking(int cur) {
    if(selected.size() == M) {
        int dist = 0;
        for(const auto &[x1, y1] : house) {
            int d = 2501;
            for(const auto &[x2, y2] : selected)
                d = min(d, abs(x1 - x2) + abs(y1 - y2));
            dist += d;
        }
        ans = min(ans, dist);
        return;
    }
    for(int i = cur; i <= chicken.size() - M + selected.size(); i++) {
        selected.push_back(chicken[i]);
        backTracking(i+1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) 
                house.push_back({i, j});
            else if(board[i][j] == 2) 
                chicken.push_back({i, j});
        } 
    }
    backTracking(0);
    cout << ans;
}