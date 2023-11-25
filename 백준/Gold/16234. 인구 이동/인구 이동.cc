#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct xy {int x, y;};
struct association {
    int tot;
    vector<xy> nations;
};
int N, L, R;
int board[50][50];
int vis[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

association getAssociation(int startX, int startY, int mark) {
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

    if(not nations.empty()) {
        tot += board[startX][startY];
        nations.push_back({startX, startY});
    }
    return {tot, nations};
}
bool migrate(const association &assoc) {
    if(assoc.nations.empty()) return false;
    int pop = assoc.tot / assoc.nations.size();
    for(const auto &[x, y]:assoc.nations) board[x][y] = pop;
    return true;
}
bool updateAssociation(int mark) {
    bool isUpdated = false;
    for(int x=0; x<N; x++) {
        for(int y=0; y<N; y++) {
            if(vis[x][y] == mark) continue;
            if(migrate(getAssociation(x, y, mark)))
                isUpdated = true;
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
    while(updateAssociation(day + 1)) day++;
    cout << day;
}