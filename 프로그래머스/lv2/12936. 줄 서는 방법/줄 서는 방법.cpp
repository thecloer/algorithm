#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(int n, long long k) {
    long long tot = 1;
    list<int> used = {1};
    for(int i=2; i<=n; i++) {
        tot *= i;
        used.push_back(i);
    };
    vector<int> ans;
    for(int i=n; i>0; i--) {
        long long sub = tot/i;
        long long mx = sub;
        auto x = used.begin();
        while(x != used.end()) {
            if(k <= mx) {
                ans.push_back(*x);
                x = used.erase(x);
                k -= mx - sub;
                tot = sub;
                break;
            } 
            mx += sub;
            ++x;
        }
    }
    return ans;
}