#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        unordered_map<string, int> freq;
        int N; cin >> N;
        if(N == 0) {
            cout << 0 << '\n';
            continue;
        }
        while(N--) {
            string x, kind;
            cin >> x >> kind;
            if(freq.find(kind) == freq.end())
                freq[kind] = 1;
            else freq[kind]++;
        }
        
        int ans = 1;
        for(const auto [kind, fq]:freq)
            ans *= fq + 1;
        cout << ans - 1 << '\n';
    }
}