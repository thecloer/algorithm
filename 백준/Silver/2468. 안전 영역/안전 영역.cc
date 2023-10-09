#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct xy {int x, y;};
int board[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    set<int> H;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            H.insert(board[i][j]);
        }
    }
    int ans = 1;
    queue<xy> Q;
    for(auto it = ++H.rbegin(); it != H.rend(); it++) {
        int cnt = 0, h = *it;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] <= h) continue;
                cnt++;
                board[i][j] = h;
                Q.push({i, j});
                while(!Q.empty()) {
                    xy cur = Q.front(); Q.pop();
                    for(int d=4; d--;) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                        if(board[nx][ny] <= h) continue;
                        board[nx][ny] = h;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        if(cnt > ans) ans = cnt;
    }
    cout << ans;
}