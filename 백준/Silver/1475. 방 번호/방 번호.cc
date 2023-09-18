#include <iostream>
using namespace std;

int a[10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int N, mx=0;
  cin >> N;
  while(N>0){
    a[N%10]++;
    N/=10;
  }
  a[6] = (a[6]+a[9]+1)/2;
  for(int i=0; i<9; i++)
    if(a[i]>mx) mx=a[i];
  cout << mx;
}