#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int R, C, K;
int rowSize = 3, colSize = 3;
int matrix[100][100];

void transpose() {
    int mx = max(rowSize, colSize);
    for(int i=0; i<mx; i++)
        for(int j=i+1; j<mx; j++)
            swap(matrix[i][j], matrix[j][i]);
    swap(rowSize, colSize);
}
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    R--; C--; // 0-based
    for(int i=0; i<rowSize; i++)
        for(int j=0; j<colSize; j++)
            cin >> matrix[i][j];
    
    int sec = 0;
    while(matrix[R][C] != K and ++sec <= 100) {
        bool transposed = false;
        if(rowSize < colSize) {
            transpose();
            transposed = true;
        }
        operateR();
        
        if(transposed) transpose();
    }
    cout << (sec > 100 ? -1 : sec);
}