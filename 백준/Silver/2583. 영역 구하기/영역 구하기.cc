#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct xy {int x, y;};
bool board[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;
    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=x1; x<x2; x++)
            for(int y=y1; y<y2; y++)
                if(!board[x][y])
                    board[x][y] = 1;
    }

    priority_queue<int, vector<int>, greater<int>> area;
    queue<xy> Q;
    for(int x=0; x<N; x++) {
        for(int y=0; y<M; y++) {
            if(board[x][y]) continue;
            board[x][y] = 1;
            int cnt = 1;
            Q.push({x, y});
            while(!Q.empty()) {
                xy cur = Q.front(); Q.pop();
                for(int d=4; d--;) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];
                    if(nx<0 || nx >=N || ny<0 || ny>=M) continue;
                    if(board[nx][ny]) continue;
                    board[nx][ny] = 1;
                    Q.push({nx, ny});
                    cnt++;
                }
            }
            area.push(cnt);
        }
    }
    cout << area.size() << '\n';
    while(!area.empty()) {
        cout << area.top() << ' ';
        area.pop();
    }
}