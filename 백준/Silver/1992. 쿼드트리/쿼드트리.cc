#include <iostream>
#include <string>
using namespace std;
bool image[64][64];

bool check(int x, int y, int w) {
    for(int i=x; i<x+w; i++)
        for(int j=y; j<y+w; j++)
            if(image[x][y] ^ image[i][j])
                return false;
    return true;
}
void qt(int x, int y, int w) {
    if(check(x, y, w)) {
        cout << image[x][y];
        return;
    }
    w /= 2;
    cout << '(';
    for(int i=0; i<4; i++)
        qt(x + w*(i>>1), y + w*(i&1), w);
    cout << ')';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string str; cin >> str;
        for(int j=0; j<N; j++)
            image[i][j] = (str[j] == '1');
    }
    qt(0, 0, N);
}