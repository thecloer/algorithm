#include <iostream>
#include <stack>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  long long ans=0;
  int n;
  cin >> n;
  stack<int> S;
  while(n--){
    int h;
    cin >> h;
    while(!S.empty() && S.top() <= h)
      S.pop();
    if(!S.empty())
      ans += S.size();
    S.push(h);
  }
  cout << ans;
}