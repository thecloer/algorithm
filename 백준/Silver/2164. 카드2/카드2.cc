#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N; cin >> N;
  int arr[N];
  for(int i=0; i<N; i++) arr[i] = i+1;

  bool select = true;

  while(N > 1){
    bool isOdd = N & 1;
    N = (N + 1 - select) / 2;
    for(int i=0; i<N; i++) 
      arr[i] = arr[2*i + select];

    if(isOdd) select = !select;
  }
  cout << arr[0];
}