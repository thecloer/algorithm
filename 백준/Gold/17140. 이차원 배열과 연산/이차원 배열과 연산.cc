#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int SIZE_LIMIT = 100;

int R, C, K;
int rowSize = 3, colSize = 3, sec;
int matrix[SIZE_LIMIT][SIZE_LIMIT];
int tmp[SIZE_LIMIT];

void operateR() {
    int maxLen = 0;
    for(int row=0; row<rowSize; row++) {
        unordered_map<int, int> freq;
        for(int i = 0; i < colSize; i++)
            if(matrix[row][i])
                freq[matrix[row][i]]++;
        
        vector<pair<int, int>> v;
        for(const auto [n, f]:freq)
            v.push_back({ f, n });
        sort(v.begin(), v.end());

        int len = 0;
        for(const auto [f, n]:v) {
            matrix[row][len++] = n;
            matrix[row][len++] = f;
        }

        for(int i=len; i<colSize; i++) matrix[row][i] = 0;
        maxLen = max(maxLen, len);
    }
    colSize = maxLen;
}
void operateC() {
    int maxLen = 0;
    for(int col=0; col<colSize; col++) {
        unordered_map<int, int> freq;
        for(int i = 0; i < rowSize; i++)
            if(matrix[i][col])
                freq[matrix[i][col]]++;
        
        vector<pair<int, int>> v;
        for(const auto [n, f]:freq)
            v.push_back({ f, n });
        sort(v.begin(), v.end());

        int len = 0;
        for(const auto [f, n]:v) {
            matrix[len++][col] = n;
            matrix[len++][col] = f;
        }

        for(int i=len; i<rowSize; i++) matrix[i][col] = 0;
        maxLen = max(maxLen, len);
    }
    rowSize = maxLen;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    R--; C--; // 0-based
    for(int i=0; i<rowSize; i++)
        for(int j=0; j<colSize; j++)
            cin >> matrix[i][j];
    while(matrix[R][C] != K and ++sec < 101) {
        if(rowSize < colSize) operateC();
        else operateR();
    }
    cout << (sec == 101 ? -1 : sec);
}