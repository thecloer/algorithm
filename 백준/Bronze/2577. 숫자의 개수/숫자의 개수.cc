#include <iostream>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  int x = a*b*c;

  int d[10]={};
  while(x > 0){
    d[x % 10]++;
    x/=10;
  }
  for(int i=0; i<10; i++)
    cout << d[i] << '\n';
}