#include <iostream>
#include <vector>
using namespace std;

struct xy {int x, y;};
bool board[101][101];
xy dxy[] = {{1,0},{0,-1},{-1,0},{0,1}};

inline void mark(const xy &pos) {
    if(!board[pos.x][pos.y]) board[pos.x][pos.y] = true;
}
void copyClockwise90(vector<xy> &path) {
    xy pin = path.back();
    vector<xy> copy;
    for(auto i = path.rbegin()+1; i != path.rend(); i++) {
        int x = i->x - pin.x;
        int y = i->y - pin.y;

        int tmp = x;
        x = -y;
        y = tmp;

        x += pin.x;
        y += pin.y;

        copy.push_back({x, y});
        mark(copy.back());
    }
    for(const auto &v:copy) path.push_back(v);
}
void curve(vector<xy> &path, int d, int g) {
    if(g == 0) {
        path.push_back({path.back().x + dxy[d].x, path.back().y + dxy[d].y});
        mark(path.back());
        return;
    }
    curve(path, d, g-1);
    copyClockwise90(path);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while(N--) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        vector<xy> path = {{x, y}};
        mark(path.front());
        curve(path, d, g);
    }
    int ans = 0;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            if(board[i][j] && board[i+1][j] 
            && board[i][j+1] && board[i+1][j+1]) ans++;
    cout << ans;
}