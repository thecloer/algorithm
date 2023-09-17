#include <iostream>
using namespace std;

void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[21];
  for(int i=1; i<21; i++)
    arr[i] = i;
  
  int s, e, tmp;
  for(int i=0; i<10; i++){
    cin >> s >> e;
    for(int j=0, k=(e-s+1)/2; j<k; j++)
      swap(arr[s+j],arr[e-j]);
  }
  
  for(int i=1; i<21; i++)
    cout << arr[i] << ' ';
}