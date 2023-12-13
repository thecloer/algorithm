#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

enum State { EMPTY, GREEN, RED, FLOWER };
struct xy {int x, y;};
int N, M, G, R, Y;
int board[50][50];
int dist[50][50];
State state[50][50];
State mask[10];
xy yellow[10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                yellow[Y++] = {i, j};
        }
    }

    for(int i=0; i<Y; i++) {
        if(i < Y-G-R) mask[i] = EMPTY;
        else if(i < Y-G) mask[i] = GREEN;
        else mask[i]= RED;
    }

    int ans = 0;
    do {
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                dist[i][j] = state[i][j] = EMPTY;
        
        queue<xy> Q;
        for(int i=0; i<Y; i++) {
            if(mask[i] == EMPTY) continue;
            state[yellow[i].x][yellow[i].y] = mask[i];
            Q.push(yellow[i]);
        }

        int flower = 0;
        while(not Q.empty()) {
            const auto [x, y] = Q.front(); Q.pop();
            if(state[x][y] == FLOWER) continue;

            for(int dir = 4; dir--;) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx<0 or nx>=N or ny<0 or ny>= M) continue;
                if(board[nx][ny] == 0) continue;
                if(state[nx][ny] == FLOWER) continue;
                if(state[nx][ny] == EMPTY) {
                    state[nx][ny] = state[x][y];
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
                else if(state[nx][ny] != state[x][y] and dist[nx][ny] == dist[x][y] + 1) {
                    state[nx][ny] = FLOWER;
                    flower++;
                }
            }
        }
        ans = max(ans, flower);
    } while(next_permutation(mask, mask+Y));
    cout << ans;
}