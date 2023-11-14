#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> user[201];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while(N--) {
        int age; string name;
        cin >> age >> name;
        user[age].push_back(name);
    }
    for(int age=1; age<201; age++)
        for(string &name:user[age])
            cout << age << ' ' << name << '\n';
}