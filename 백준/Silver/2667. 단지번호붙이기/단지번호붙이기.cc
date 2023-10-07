#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct xy {int x, y;};
char board[25][26];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++)
        cin >> board[i];

    vector<int> v;
    queue<xy> Q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == '0') continue;
            board[i][j] = '0';
            Q.push({i, j});
            int area = 1;
            while(!Q.empty()) {
                xy cur = Q.front(); Q.pop();
                for(int d=4; d--;) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    if(board[nx][ny] == '0') continue;
                    board[nx][ny] = '0';
                    Q.push({nx, ny});
                    area++;
                }
            }
            v.push_back(area);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int a:v) cout << a << '\n';
}
