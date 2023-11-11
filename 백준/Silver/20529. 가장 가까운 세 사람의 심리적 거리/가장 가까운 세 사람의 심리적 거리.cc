#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_ANS = 8, MBTI_KIND = 16, GROUP_SIZE = 3;

int N, ans;
int freq[MBTI_KIND];
int group[GROUP_SIZE];
int MBTI[2*MBTI_KIND];

int getMBTI() {
    int hashed = 0;
    for(int j=0; j<4; j++) {
        char c; cin >> c;
        hashed <<= 1;
        if(c == 'E' || c == 'N' || c == 'T' || c == 'J')
            hashed += 1;
    }
    return hashed;
}
int bitCount(int x) {
    int n = 0;
    while(x > 0) {
        if(x & 1) n++;
        x >>= 1;
    }
    return n;
}
int getDist() {
    int dist = 0;
    for(int i = 0; i < GROUP_SIZE; i++)
        dist += bitCount(group[i] xor group[(i+1) % GROUP_SIZE]);
    return dist;
}
void backTracking(int cur, int len) {
    if(len == GROUP_SIZE) {
        int dist = getDist();
        if(ans > dist) ans = dist;
        return;
    }
    for(int i = cur; i <= N - GROUP_SIZE + len; i++) {
        group[len] = MBTI[i];
        backTracking(i+1, len+1);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        ans = MAX_ANS;
        for(int i=0; i<MBTI_KIND; i++) freq[i] = 0;

        cin >> N;
        if(N > 2*MBTI_KIND) ans = 0;
        for(int i=0; i<N; i++) freq[getMBTI()]++;
        for(int i=0, k=0; i<MBTI_KIND and ans > 0; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] > 2) ans = 0;
            else while(freq[i]--) MBTI[k++] = i;
        }
        if(ans) backTracking(0, 0);
        cout << ans << '\n';
    }
}