#include <iostream>
#include <vector>
using namespace std;

int N, ans;
bool wall[17][17];
int dx[] {0, 1, 1}; // direction -> delta position
int dy[] {1, 1, 0}; // direction -> delta position
vector<int> nxt[] {{0, 1}, {0, 1, 2}, {1, 2}}; // current direction -> next directions
vector<int> check[] {{0}, {0, 1, 2}, {2}}; // next direction -> check delta positions

inline bool isValid(int x, int y) {
    return x < N and y < N and not wall[x][y];
}

void move(int dir, int x, int y) {
    if(x == N-1 and y == N-1) {
        ans++;
        return;
    }

    for(int nd:nxt[dir]) {
        int nx = x + dx[nd], ny = y + dy[nd];
        if(not isValid(nx, ny)) continue;
        
        bool pass = true;
        for(int d:check[nd]) {
            if(isValid(x + dx[d], y + dy[d])) continue;
            pass = false;
            break;
        }

        if(not pass) continue;
        move(nd, nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> wall[i][j];
    
    move(0, 0, 1);
    cout << ans;
}