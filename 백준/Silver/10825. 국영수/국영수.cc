#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct student {
    string name;
    int Kor, Eng, Math;
};

bool cmp(const student &a, const student &b) {
    if(a.Kor != b.Kor) return a.Kor > b.Kor;
    if(a.Eng != b.Eng) return a.Eng < b.Eng;
    if(a.Math != b.Math) return a.Math > b.Math;
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<student> classmate(N);
    for(auto &[name, kor, eng, mth]:classmate)
        cin >> name >> kor >> eng >> mth;
    sort(classmate.begin(), classmate.end(), cmp);
    for(const auto &p:classmate) cout << p.name << '\n';
}