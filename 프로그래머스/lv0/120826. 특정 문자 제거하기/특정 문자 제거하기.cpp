#include <string>
#include <vector>

using namespace std;

string solution(string my, string letter) {
    char c = letter[0];
    string ans = "";
    for(int i=0, s=my.size(); i<s; i++)
        if(my[i] != c)
            ans += my[i];
    return ans;
}