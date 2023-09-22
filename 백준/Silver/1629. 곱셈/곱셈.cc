#include <iostream>
using namespace std;

long long power(int a, int b, int c) {
  if(b==0) return 1;
  long long res = power(a, b/2, c);
  res = res * res % c;
  res *= (b & 1) ? a : 1;
  return res % c;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  cout << power(a%c, b, c);
}