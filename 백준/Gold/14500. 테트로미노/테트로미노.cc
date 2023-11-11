#include <iostream>
using namespace std;
const int TETROMINO_KIND = 5, TETROMINO_SIZE = 4;

struct xy { int x, y; };
struct tetromino {
    int w, h, flip, rotate;
    xy shape[TETROMINO_SIZE];
};

int board[500][500];
tetromino tetrominos[TETROMINO_KIND] = {
    { 4, 1, 1, 2, {{0, 0}, {0, 1}, {0, 2}, {0, 3}} }, // ㅡ
    { 2, 2, 1, 1, {{0, 0}, {0, 1}, {1, 0}, {1, 1}} }, // ㅁ
    { 3, 2, 2, 4, {{0, 0}, {0, 1}, {0, 2}, {1, 2}} }, // ㄱ
    { 3, 2, 2, 2, {{0, 0}, {0, 1}, {1, 1}, {1, 2}} }, // ㄹ
    { 3, 2, 1, 4, {{0, 0}, {0, 1}, {0, 2}, {1, 1}} }, // ㅜ
};
int max(const int &a, const int &b) { return a > b ? a : b; }
void flip(tetromino &tetro) {
    for(xy &point:tetro.shape) point.x = tetro.h - 1 - point.x;
}
void rotate90(tetromino &tetro) {
    int tmp = tetro.h;
    tetro.h = tetro.w;
    tetro.w = tmp;
    for(auto &[x, y]:tetro.shape) {
        tmp = y;
        y = tetro.w - 1 - x;
        x = tmp;
    }
}
int getScore(int x, int y, tetromino &tetro) {
    int score = 0;
    for(const auto &[dx, dy]:tetro.shape)
        score += board[x + dx][y + dy];
    return score;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) 
            cin >> board[i][j];
    
    int ans = 0;
    for(int tet = 0; tet < TETROMINO_KIND; tet++) {
        tetromino &curTetro = tetrominos[tet];
        for(int flipCnt = 0; flipCnt < curTetro.flip; flipCnt++) {
            for(int rotateCnt = 0; rotateCnt < curTetro.rotate; rotateCnt++) {
                for(int x = 0; x <= N - curTetro.h; x++)
                    for(int y = 0; y <= M - curTetro.w; y++)
                        ans = max(ans, getScore(x, y, curTetro));
                rotate90(curTetro);
            }
            flip(curTetro);
        }
    }
    cout << ans;
}