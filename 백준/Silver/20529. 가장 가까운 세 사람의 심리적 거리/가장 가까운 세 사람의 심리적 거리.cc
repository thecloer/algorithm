#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_ANS = 8, MBTI_KIND = 16, GROUP_SIZE = 3;

int N, ans;
int freq[MBTI_KIND];
int group[GROUP_SIZE];
vector<int> MBTI;

int hashMBTI() {
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
void backTracking(int len) {
    if(len == GROUP_SIZE) {
        int dist = getDist();
        if(ans > dist) ans = dist;
        return;
    }
    for(int i=0; i<MBTI.size(); i++) {
        if(freq[MBTI[i]] == 0) continue;
        int cnt = (freq[MBTI[i]]  == 2 && len < 2) ? 2 : 1;
        for(int j=0; j<cnt; j++)
            group[len+j] = MBTI[i];
        freq[MBTI[i]] -= cnt;
        backTracking(len+cnt);
        freq[MBTI[i]] += cnt;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        ans = MAX_ANS;
        MBTI.clear();
        for(int i=0; i<MBTI_KIND; i++) freq[i] = 0;
        
        cin >> N;
        for(int i=0; i<N; i++) freq[hashMBTI()]++;
        for(int i=0; i<MBTI_KIND; i++) {
            if(freq[i] > 2) {
                ans = 0;
                break;
            }
            if(freq[i]) MBTI.push_back(i);

        }
        if(ans == MAX_ANS) backTracking(0);
        cout << ans << '\n';
    }
}