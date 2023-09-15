#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N, a, b;
  cin >> N;
  while(N-->0) {
    cin >> a >> b;
    cout << a+b << '\n';
  }
  return 0;
}