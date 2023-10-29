#include <iostream>
using namespace std;

int N;
bool board[3072][6144];

void fillStar(int x, int y, int n) {
    if(n == 3) {
        board[x-2][y+2] = true;
        board[x-1][y+1] = board[x-1][y+3] = true;
        for(int i=0; i<5; i++) board[x][y+i] = true;
        return;
    }
    fillStar(x - n/2, y + n/2, n/2);
    fillStar(x, y, n/2);
    fillStar(x, y + n, n/2);
}
void printStar() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<2*N; j++)
            cout << (board[i][j] ? '*' : ' ');
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    fillStar(N-1, 0, N);
    printStar();
}