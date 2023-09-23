#include <iostream>
#include <stack>
using namespace std;

struct e { int idx, val; };

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int n;
  stack<e> S;
  cin >> n;
  int ans[n];
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    while(!S.empty() && S.top().val < x){
      ans[S.top().idx] = x;
      S.pop();
    }
    S.push({i, x});
  }
  while(!S.empty()){
    ans[S.top().idx] = -1;
    S.pop();
  }

  for(int x:ans)
    cout << x << ' ';
}