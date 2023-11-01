#include <iostream>
#include <vector>
using namespace std;

struct xy { int x, y; };
int N, M, ans, zeros;
int board[8][8];
vector<xy> CCTV[6];
vector<vector<int>> ways[6] = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}},
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x<0 || x>=N || y<0 || y>=M; }
int replace(int dir, int x, int y, int before, int after) {
    int cnt = 0;
    x += dx[dir]; 
    y += dy[dir];
    while(!(OOB(x, y) || board[x][y] == 6)) {
        if(board[x][y] == before) {
            board[x][y] = after;
            cnt++;
        }
        x += dx[dir]; 
        y += dy[dir];
    }
    return cnt;
}
void backTracking(int kind, int cur) {
    if(CCTV[kind].size() == cur) {
        if(kind > 1) return backTracking(kind - 1, 0);
        if(zeros == 0) {
            cout << 0;
            exit(0);
        }
        if(ans > zeros) ans = zeros;
        return;
    }
    auto [x, y] = CCTV[kind][cur];
    for(auto way : ways[kind]) {
        for(int dir : way)
            zeros -= replace(dir, x, y, 0, 100+10*x+y);
        backTracking(kind, cur + 1);
        for(int dir : way)
            zeros += replace(dir, x, y, 100+10*x+y, 0);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) zeros++;
            else if(0 < board[i][j] && board[i][j] < 6)
                CCTV[board[i][j]].push_back({i, j});
        }
    }
    ans = zeros;
    backTracking(5, 0);
    cout << ans;
}