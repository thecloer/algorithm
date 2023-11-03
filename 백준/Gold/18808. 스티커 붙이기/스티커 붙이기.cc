#include <iostream>
#include <vector>
using namespace std;

struct xy {int x, y;};
int N, M, K ,ans;
bool laptop[40][40];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void rotate90(vector<xy> &sticker, int &R, int &C) {
    swap(R, C);
    for(auto &[x, y] : sticker) {
        swap(x, y);
        y = C - 1 - y;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    while(K--) {
        int R, C; cin >> R >> C;
        vector<xy> sticker;
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                bool isSticker; cin >> isSticker;
                if(isSticker) sticker.push_back({r, c});
            }
        }

        bool sticked = false;
        for(int rot=4; not sticked and rot--;) {
            if(rot != 3) rotate90(sticker, R, C);
            for(int i=0; not sticked and i<=N-R; i++) {
                for(int j=0; not sticked and j<=M-C; j++) {
                    bool canStick = true;
                    for(const auto &[x, y] : sticker) {
                        if(laptop[i+x][j+y]) {
                            canStick = false;
                            break;
                        }
                    }
                    if(not canStick) continue;
                    for(const auto &[x, y] : sticker) 
                        laptop[i+x][j+y] = true;
                    sticked = true;
                }
            }
        }
        if(sticked) ans += sticker.size();
    }
    cout << ans;
}