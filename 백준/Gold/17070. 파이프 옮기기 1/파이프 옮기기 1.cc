#include <iostream>
using namespace std;

int N;
bool isWall[17][17];
int way[17][17][3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> isWall[i][j];
    
    way[1][2][0] = 1;
    for(int x=1; x<=N; x++) {
        for(int y=1; y<=N; y++) {
            if(isWall[x][y]) continue;
            way[x][y][0] += way[x][y-1][0] + way[x][y-1][1];
            way[x][y][2] += way[x-1][y][1] + way[x-1][y][2];
            if(isWall[x-1][y] or isWall[x][y-1]) continue;
            way[x][y][1] += way[x-1][y-1][0] + way[x-1][y-1][1] + way[x-1][y-1][2];
        }
    }
    cout << way[N][N][0] + way[N][N][1] + way[N][N][2];
}