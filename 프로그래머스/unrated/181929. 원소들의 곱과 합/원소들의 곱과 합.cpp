#include <string>
#include <vector>

using namespace std;

int solution(vector<int> lst) {
    int s=0, p=1;
    for(int n:lst){
        s+=n;
        p*=n;
    }
    return p<s*s;
}