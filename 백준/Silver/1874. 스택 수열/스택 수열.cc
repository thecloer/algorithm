#include <iostream>
#include <stack>
#include <list>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N, n, x, k=1;
  stack<int> S;
  list<char> ans;
  cin >> N;
  n = N;
  while(n--){
    cin >> x;
    while(S.empty() || k <= x) {
      ans.push_back('+');
      S.push(k++);
    }
    if(S.top() == x) {
      ans.push_back('-');
      S.pop();
    } else break;
  }
  if(ans.size() == 2*N) 
    for(char c:ans) cout << c << '\n';
  else cout << "NO";
}