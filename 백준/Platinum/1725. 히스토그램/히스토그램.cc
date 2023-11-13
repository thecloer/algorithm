#include <iostream>
#include <stack>
using namespace std;

struct rect { int idx, h; };

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    int ans = 0;
    stack<rect> S;
    for(int i = 0; i <= n; i++){
        int h = 0, idx = i;
        if(i != n) cin >> h;
        while(!S.empty() && S.top().h > h) {
            idx = S.top().idx;
            ans = max(ans,  S.top().h * (i - idx));
            S.pop();
        }
        if(S.empty() || S.top().h != h)
            S.push({idx, h});
    }
    cout << ans;
}