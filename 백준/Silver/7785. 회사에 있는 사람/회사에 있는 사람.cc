#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    map<string, bool> office;
    while(N--) {
        string name, action; cin >> name >> action;
        if(action == "enter") office[name] = true;
        else office[name] = false;
    }
    for(auto iter=office.rbegin(); iter != office.rend(); iter++) 
        if(iter->second) cout << iter->first << '\n';
}