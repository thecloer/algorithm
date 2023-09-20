#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int n, k=1;
  stack<int> S;
  string ans;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    while(k <= x) {
      ans += "+\n";
      S.push(k++);
    }
    if(S.top() != x) {
      cout << "NO";
      return 0;
    }
    ans += "-\n";
    S.pop();
  }
  cout << ans;
}