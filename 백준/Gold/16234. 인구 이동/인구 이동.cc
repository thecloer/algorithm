#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct xy {int x, y;};
int N, L, R;
int board[50][50], vis[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool migrate(int startX, int startY, int mark) {
    int tot = 0;
    vector<xy> nations;

    queue<xy> Q;
    Q.push({startX, startY});
    vis[startX][startY] = mark;
    while(not Q.empty()) {
        const auto [x, y] = Q.front(); Q.pop();
        for(int d=4; d--;) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx<0 or nx>=N or ny<0 or ny>=N) continue;
            if(vis[nx][ny] == mark) continue;
            int diff = abs(board[x][y] - board[nx][ny]);
            if(diff < L or diff > R) continue;
            vis[nx][ny] = mark;
            Q.push({nx, ny});

            tot += board[nx][ny];
            nations.push_back({nx, ny});
        }
    }

    if(nations.empty()) return false;
    
    tot += board[startX][startY];
    nations.push_back({startX, startY});

    int pop = tot / nations.size();
    for(const auto &[x, y]:nations) board[x][y] = pop;
    return true;
}
bool findNewAssociation(int mark) {
    bool isUpdated = false;
    for(int x=0; x<N; x++) {
        for(int y=0; y<N; y++) {
            if(vis[x][y] == mark) continue;
            if(migrate(x, y, mark)) isUpdated = true;
        }
    }
    return isUpdated;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    int day = 0;
    while(findNewAssociation(day + 1)) day++;
    cout << day;
}