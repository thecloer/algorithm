#include <iostream>
using namespace std;
const int MAX_ANS = 8, MBTI_KIND = 16, GROUP_SIZE = 3;
const char HASH_MAP[] = {'E', 'N', 'T', 'J'};

int N, ans;
int MBTI[2*MBTI_KIND];
int group[GROUP_SIZE];

int min(const int &a, const int &b) {return a < b ? a : b;}
int getHashedMBTI() {
    int hashed = 0;
    for(int i=0; i<4; i++) {
        char c; cin >> c;
        hashed <<= 1;
        if(c == HASH_MAP[i]) hashed++;
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
    if(ans < 2) return;
    if(len == GROUP_SIZE) {
        ans = min(ans, getDist());
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
        cin >> N;
        ans = (N > 2*MBTI_KIND) ? 0 : MAX_ANS;
        int freq[MBTI_KIND] = {};
        for(int i=0; i<N; i++) freq[getHashedMBTI()]++;
        for(int i=0, k=0; i<MBTI_KIND and ans; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] > 2) ans = 0;
            else while(freq[i]--) MBTI[k++] = i;
        }
        backTracking(0, 0);
        cout << ans << '\n';
    }
}