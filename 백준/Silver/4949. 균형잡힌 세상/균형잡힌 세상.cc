#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	string line;
	getline(cin, line);
	while(line != ".") {
		stack<char> S;
		bool isOk = true;
		for(char c:line){
			if(c == '(' || c == '[') S.push(c);
			else if(c == ')' || c == ']') {
				if((c == ')' && !S.empty() && S.top() == '(') 
				|| (c == ']' && !S.empty() && S.top() == '[')) {
					S.pop();
				} else {
					isOk = false;
					break;
				}
			}
		}
		cout << (S.empty() && isOk ? "yes\n" : "no\n");
		getline(cin, line);
	}
}