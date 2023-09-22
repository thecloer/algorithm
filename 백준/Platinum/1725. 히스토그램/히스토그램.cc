#include <iostream>
#include <stack>
using namespace std;
#define idx first
#define height second

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  stack<pair<int, int>> s;
  long long ans = 0;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x, idx=i;
    cin >> x;
    while(!s.empty() && s.top().height > x){
      auto t = s.top(); 
      s.pop();
      ans = max(ans, 1LL * t.height * (i - t.idx));
      idx = t.idx;
    }
    if(s.empty() || x != s.top().height) 
      s.push({idx, x});
  }
  while(!s.empty()){
      ans = max(ans, 1LL * s.top().height * (n - s.top().idx));
      s.pop();
  }
  cout << ans;
}