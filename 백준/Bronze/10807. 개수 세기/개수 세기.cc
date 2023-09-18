#include <iostream>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int N, v, ans=0;
  int a[100];
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> a[i];
  cin >>v;
  for(int i=0; i<N; i++)
    if(a[i]==v) ans++;
  cout<<ans;
}