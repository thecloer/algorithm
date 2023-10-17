using namespace std;

int solution(int storey) {
    int ans = 0;
    while(storey) {
        while(storey % 10 == 0) 
            storey /= 10;
        
        int mod = storey % 10;
        if(mod == 5) {
            if(storey > 5 && storey % 100 >= 55)
                storey += 5;
            else
                storey -= 5;
            ans += 5;
        }
        else if(10 - mod < mod) {
            storey += 10 - mod;
            ans += 10 - mod;
        } else {
            storey -= mod;
            ans += mod;
        }
    }
    return ans;
}