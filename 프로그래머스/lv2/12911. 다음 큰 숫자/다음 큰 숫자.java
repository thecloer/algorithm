class Solution {
    public int solution(int n) {
        int o = countOneBit(n);
        
        int p=0;
        while((n&(3<<p)) != (1<<p))
            p++;
        p++;
        
        int ans = (n&(-1<<p)) + (1<<p);
        ans += (1<<(o-countOneBit(ans)))-1;
        return ans;
    }
    
    int countOneBit(int n){
        int o=0;
        while(n>0){
            n &= n-1;
            o++;
        }
        return o;
    }
}