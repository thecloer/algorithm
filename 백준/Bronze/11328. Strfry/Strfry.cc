#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int N;
  cin >> N;
  while(N--){
    string a,b;
    cin >> a >> b;
    int aa[26] = {};
    int bb[26] = {};
    if(a.length() == b.length()){
      for(int i=0; i<a.length(); i++){
        aa[a[i]-'a']++; 
        bb[b[i]-'a']++;
      }
      bool isPossible = true;
      for(int i=0; i<26; i++){
        if(aa[i] != bb[i]) {
          isPossible = false;
          break;
        }
      }
      if(isPossible){
        cout << "Possible\n";  
        continue;
      }
    } 
    cout << "Impossible\n";
  }
}