#include <iostream>
#include <string>
using namespace std;

int N, ans;
char board[50][50];
void swap(char &a, char&b) {
    char tmp = a; a = b; b = tmp;
}
void checkRow(int row) {
    int cnt = 1;
    for(int i=1; i<N; i++) {
        if(board[row][i] == board[row][i-1]) {
            cnt++;
            if(cnt > ans) ans = cnt;
        } else cnt = 1;
    }
}
void checkCol(int col) {
    int cnt = 1;
    for(int i=1; i<N; i++) {
        if(board[i][col] == board[i-1][col]) {
            cnt++;
            if(cnt > ans) ans = cnt;
        } else cnt = 1;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> board[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i < N-1) {
                swap(board[i][j], board[i+1][j]);
                checkCol(j);
                checkRow(i);
                checkRow(i+1);
                swap(board[i][j], board[i+1][j]);
            }
            if(j < N-1) {
                swap(board[i][j], board[i][j+1]);
                checkRow(i);
                checkCol(j);
                checkCol(j+1);
                swap(board[i][j], board[i][j+1]);
            }
        }
    }
    cout << ans;
}