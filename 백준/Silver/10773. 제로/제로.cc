#include <iostream>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int K, x, len=0, ans=0;
  cin >> K;
  int stack[K];

  while(K--){
    cin >> x;
    if(x) stack[len++] = x;
    else len--;
  }

  for(int i=0; i<len; i++)
    ans += stack[i];
  cout << ans;
}