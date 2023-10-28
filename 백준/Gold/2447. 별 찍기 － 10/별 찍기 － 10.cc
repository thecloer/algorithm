#include <iostream>
#include <string>
using namespace std;

int N;
char board[6561][6561];

void fillEmpty(int x, int y, int size) {
    for(int i=x; i<x+size; i++)
        for(int j=y; j<y+size; j++)
            board[i][j] = ' ';
}
void fillStar(int x, int y, int size) {
    if(size == 1) {
        board[x][y] = '*';
        return;
    }
    int nxt = size/3;
    for(int i=x; i<x+size; i+=nxt) {
        for(int j=y; j<y+size; j+=nxt) {
            if(i == x+nxt && j == y+nxt) fillEmpty(i, j, nxt);
            else fillStar(i, j, nxt);
        }
    }
}
void printStar(){
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout << board[i][j];
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fillStar(0, 0, N);
    printStar();
}