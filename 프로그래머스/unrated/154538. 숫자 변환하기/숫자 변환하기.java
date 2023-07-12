class Solution {
    public int solution(int x, int y, int n) {
        int[] dp = new int[y-x+1];
        dp[0] = 1;
        for(int i=1; i<dp.length; i++){
            if(i>=n && dp[i-n]>0)
                dp[i] = dp[i-n]+1;
            for(int d=2; d<=3; d++)
                if((x+i)%d==0 && (x+i)>=d*x && dp[(x+i)/d-x]>0)
                    dp[i] = dp[i]>0 ? Math.min(dp[(x+i)/d-x]+1, dp[i]) : dp[(x+i)/d-x]+1;
        }
        return dp[y-x] - 1;
    }
}