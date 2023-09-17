#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int mx, idx=1;
  cin >> mx;
  for(int i=2; i<=9; i++){
    int a;
    cin >> a;
    if(a>mx){
      mx = a;
      idx = i;
    }
  }
  cout << mx << '\n' << idx;
}