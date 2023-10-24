#include <iostream>
using namespace std;

int paper[2187][2187];
int ans[3];
void cut(int x, int y, int n) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(paper[x][y] == paper[i][j]) continue;
            for(int k=0; k<9; k++)
                cut(x + (n/3)*(k/3), y + (n/3)*(k%3), n/3);
            return;
        }
    }
    ans[paper[x][y] + 1]++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> paper[i][j];

    cut(0, 0, N);
    for(int a:ans) cout << a << '\n';
}