#include <iostream>
#include <stack>
using namespace std;

struct element { int idx, height; };

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int n, ans = 0;
  cin >> n;
  stack<element> S;
  for(int i=0; i<=n; i++){
    int x = 0, idx = i;
    if(x != n) cin >> x;
    while(!S.empty() && S.top().height > x) {
      int h = S.top().height;
      int w = i - S.top().idx;
      idx = S.top().idx;
      ans = max(ans, h * w);
      S.pop();
    }
    if(S.empty() || S.top().height != x)
      S.push({idx, x});
  }
  cout << ans;
}