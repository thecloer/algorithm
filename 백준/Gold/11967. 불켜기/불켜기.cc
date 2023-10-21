#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct xy {int x, y;};
int N, M;
bool lights[101][101];
bool vis[101][101];
vector<xy> btns[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<xy> Q;

bool OoB(int x, int y) {return x<1 || x>N || y<1 || y>N;};
bool isConnected(xy &pos) {
    for(int i=4; i--;) {
        int nx = pos.x + dx[i], ny = pos.y + dy[i];
        if(OoB(nx, ny)) continue;
        if(vis[nx][ny]) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while(M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        btns[x][y].push_back({a, b});
    }

    int cnt = 1;
    lights[1][1] = true;
    vis[1][1] = true;
    Q.push({1, 1});
    while(!Q.empty()) {
        xy cur = Q.front(); Q.pop();
        auto &curBtns = btns[cur.x][cur.y];
        while(!curBtns.empty()) {
            xy &btn = curBtns.back(); curBtns.pop_back();
            if(lights[btn.x][btn.y]) continue;
            lights[btn.x][btn.y] = true;
            cnt++;
            if(isConnected(btn)) {
                Q.push(btn);
                vis[btn.x][btn.y] = true;
            }
        }
        for(int i=4; i--;) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if(nx<1 || nx>N || ny<1 || ny>N) continue;
            if(vis[nx][ny] || !lights[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    cout << cnt;
}