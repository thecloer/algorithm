#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char input[15], output[15];

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void backTracking(int cur, int len, int vowelCnt) {
    if(len == L) {
        if(vowelCnt < 1 || len-vowelCnt < 2) return;
        for(int i=0; i<L; i++) cout << output[i];
        cout << '\n';
        return;
    }
    for(int i=cur; i<C; i++) {
        output[len] = input[i];
        backTracking(i+1, len+1, vowelCnt + isVowel(input[i]));
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++) cin >> input[i];

    sort(input, input+C);
    backTracking(0, 0, 0);
}