#include <iostream>
#include <unordered_map>
using namespace std;
const int FACE_LENGTH = 8, SIDE_LENGTH = 12;

char cube[48];
char color[6] = {'w', 'g', 'r', 'b', 'o', 'y'};
unordered_map<char, int> keyMap = {
    {'U', 0}, {'L', 1}, {'F', 2}, {'R', 3}, {'B', 4}, {'D', 5}
};
int faceIndex[6][FACE_LENGTH] = {
    {0, 1, 2, 3, 4, 5, 6, 7}, // U
    {8, 9, 10, 11, 12, 13, 14, 15}, // L
    {16, 17, 18, 19, 20, 21, 22, 23}, // F
    {24, 25, 26, 27, 28, 29, 30, 31}, // R
    {32, 33, 34, 35, 36, 37, 38, 39}, // B
    {40, 41, 42, 43, 44, 45, 46, 47} // D
};
int sideIndex[6][SIDE_LENGTH] = {
    {34, 33, 32, 26, 25, 24, 18, 17, 16, 10, 9, 8}, // U
    {0, 7, 6, 16, 23, 22, 40, 47, 46, 36, 35, 34}, // L
    {6, 5, 4, 24, 31, 30, 42, 41, 40, 12, 11, 10}, // F
    {4, 3, 2, 32, 39, 38, 44, 43, 42, 20, 19, 18}, // R
    {2, 1, 0, 8, 15, 14, 46, 45, 44, 28, 27, 26}, // B
    {22, 21, 20, 30, 29, 28, 38, 37, 36, 14, 13, 12} // D
};

void rotate(int index[], int n, int offset) {
    int tmp[n];
    for(int i = 0, t = offset; i < n; i++) {
        tmp[t++] = cube[index[i]];
        if(t == n) t %= n;
    }
    for(int i=0; i<n; i++) cube[index[i]] = tmp[i];
}
void rotateFace(int face, bool isClockwise) {
    int rot = isClockwise ? 1 : 3;
    rotate(faceIndex[face], FACE_LENGTH, 2*rot);
    rotate(sideIndex[face], SIDE_LENGTH, 3*rot);
}
void printUp() {
    int ln = 0;
    for(int i : {0, 1, 2, 7, -1, 3, 6, 5, 4}) {
        if(i < 0) cout << 'w';
        else cout << cube[i];
        if(++ln % 3 == 0) cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        for(int i=0; i<48; i++) cube[i] = color[i/8];
        int n; cin >> n;
        while(n--) {
            char face, sign; cin >> face >> sign;
            rotateFace(keyMap[face], sign == '+');
        }
        printUp();
    }
}