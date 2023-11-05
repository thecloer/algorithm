#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string names[100001];
map<string, int> nums;

int parseInt(string &s) {
    int n = 0;
    for(char c:s) {
        if(!isdigit(c)) return 0;
        n = 10*n + c-'0';
    }
    return n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int num=1; num<=N; num++) {
        string name; cin >> name;
        nums.insert({name, num});
        names[num] = name;
    }
    while(M--) {
        string name; cin >> name;
        int num = parseInt(name);
        if(num) cout << names[num] << '\n';
        else cout << nums[name] << '\n';
    }
}