#include <iostream>
#include <stack>
using namespace std;
#define idx first
#define height second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  long long ans = 0;
  int n;
  cin >> n;
  stack<pair<int,int>> S;
  for(int i=0; i<=n; i++){
    int x = 0, idx = i;
    if(x != n) cin >> x;
    while(!S.empty() && S.top().height > x) {
      int h = S.top().height;
      int w = i - S.top().idx;
      idx = S.top().idx;
      ans = max(ans, 1LL * h * w);
      S.pop();
    }
    if(S.empty() || S.top().height != x)
      S.push({idx, x});
  }
  cout << ans;
}