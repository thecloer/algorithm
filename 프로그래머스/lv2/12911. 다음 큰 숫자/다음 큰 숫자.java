class Solution {
    public int solution(int n) {
        int o = Integer.bitCount(n);        
        int p=0;
        while((n&(3<<p)) != (1<<p))
            p++;
        p++;
        
        int ans = (n&(-1<<p)) + (1<<p);
        ans += (1<<(o-Integer.bitCount(ans)))-1;
        return ans;
    }
}