#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int N, v;
  int a[201]={};
  cin >> N;
  for(int i=0; i<N; i++){
    int t;
    cin >> t;
    a[t+100]++;
  }
  cin >> v;
  cout << a[v+100];
}