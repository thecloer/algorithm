#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct xy {int x, y;};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, shark = 2, feed = 0, mark = 0;
int board[21][21];
int vis[21][21];
xy loc;

bool xyMin(const xy &a, const xy &b) {
    if(a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}

int findNear() {
    priority_queue<xy, vector<xy>, decltype(&xyMin)> minQ(xyMin);
    queue<xy> Q;
    vis[loc.x][loc.y] = ++mark;
    Q.push(loc);
    int dist = 0;
    while(!Q.empty() && minQ.empty()) {
        dist++;
        int size = Q.size();
        while(size--) {
            xy cur = Q.front(); Q.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                if(vis[nx][ny] == mark) continue;
                if(board[nx][ny] > shark) continue;
                if(board[nx][ny] && board[nx][ny] < shark)
                    minQ.push({nx, ny});
                else {
                    vis[nx][ny] = mark;
                    Q.push({nx, ny});
                }
            }
        }
    }
    if(minQ.empty()) return 0;
    loc = minQ.top();
    return dist;
}
void eat() {
    board[loc.x][loc.y] = 0;
    if(++feed == shark) {
        shark++;
        feed = 0;
    }
}
int move() {
    int dist = findNear();
    if(dist) eat();
    return dist;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                loc = {i, j};
                board[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for(int t = move(); t; t = move()) 
        ans += t;
    cout << ans;
}