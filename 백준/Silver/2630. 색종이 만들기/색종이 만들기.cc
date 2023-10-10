#include <iostream>
using namespace std;

int board[128][128];
int W, B;

void check(int n, int x, int y) {
    bool isBlue = board[x][y], same = true;
    for(int i=0; i<n && same; i++)
        for(int j=0; j<n && same; j++)
            if(board[x+i][y+j] != isBlue)
                same = false;
    if(same) {
        if(isBlue) B++;
        else W++;
        return;
    }
    n /= 2;
    check(n, x, y);
    check(n, x+n, y);
    check(n, x, y+n);
    check(n, x+n, y+n);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    check(n, 0, 0);
    cout << W << '\n' << B;
}