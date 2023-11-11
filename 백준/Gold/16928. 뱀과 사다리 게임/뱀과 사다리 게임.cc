#include <iostream>
#include <queue>
using namespace std;

int board[101], jump[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, from, to;
    cin >> N >> M;
    while(N--) cin >> from >> jump[from];
    while(M--) cin >> from >> jump[from];
    queue<int> Q;
    Q.push(1);
    while(!board[100]) {
        int x = Q.front(); Q.pop();
        for(int dice = 1; dice <= 6; dice++) {
            int nx = x + dice;
            if(jump[nx]) nx = jump[nx];
            if(nx > 100 || nx < 1) continue;
            if(board[nx] && board[nx] < board[x] + 1) continue;
            board[nx] = board[x] + 1;
            Q.push(nx);
        }
    }
    cout << board[100];
}