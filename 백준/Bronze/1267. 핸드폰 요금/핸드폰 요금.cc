#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, x, Y=0, M=0;
  cin >> N;
  while(N--){
    cin >> x;
    Y += 10 * (x / 30 + 1);
    M += 15 * (x / 60 + 1);
  }
  if(M == Y)
    cout << "Y M " << M;
  else if(M < Y) 
    cout << "M " << M;
  else
    cout << "Y " << Y;
}