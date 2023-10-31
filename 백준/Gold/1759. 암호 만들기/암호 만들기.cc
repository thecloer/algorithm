#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char vowels[5], consonants[14];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int L, C; cin >> L >> C;
    int vLen = 0, cLen = 0;
    for(int i=0; i<C; i++) {
        char c; cin >> c;
        if(c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u') 
            vowels[vLen++] = c;
        else consonants[cLen++] = c;
    }
    sort(vowels, vowels+vLen);
    sort(consonants, consonants+cLen);

    vector<string> ans;
    for(int vCnt = max(1, L-cLen); vCnt <= min(vLen, L-2); vCnt++) {
        int cCnt = L - vCnt;
        int vMask[vLen], cMask[cLen];
        for(int i=0; i<vLen; i++) vMask[i] = i < vCnt ? 0 : 1;
        for(int i=0; i<cLen; i++) cMask[i] = i < cCnt ? 0 : 1;
        do {
            do {
                string s;
                for(int i=0; i<vLen; i++)
                    if(!vMask[i]) s.push_back(vowels[i]);
                for(int i=0; i<cLen; i++) 
                    if(!cMask[i]) s.push_back(consonants[i]);
                sort(s.begin(), s.end());
                ans.push_back(s);
            } while(next_permutation(cMask, cMask + cLen));
        } while(next_permutation(vMask, vMask + vLen));
    }
    sort(ans.begin(), ans.end());
    for(string s:ans)
        cout << s << '\n';
}