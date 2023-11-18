#include <iostream>
using namespace std;

int step[301], score[301];
inline int max(int a, int b) {return a > b ? a : b;}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> step[i];
    score[1] = step[1];
    score[2] = step[1] + step[2];
    score[3] = step[3] + max(step[1], step[2]);
    for(int i=4; i<=N; i++)
        score[i] = step[i] + max(score[i-2], step[i-1] + score[i-3]);
    cout << score[N];
}