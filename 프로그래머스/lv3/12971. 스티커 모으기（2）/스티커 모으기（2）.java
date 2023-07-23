import java.util.*;
class Solution {
    public int solution(int sticker[]) {
        int answer = 0;
        if(sticker.length<4) {
            for(int s:sticker)
                answer = Math.max(answer,s);
            return answer;
        }
        
        int[] dp;
        for(int start=0; start<2; start++){
            dp = Arrays.copyOfRange(sticker, start, sticker.length-1 + start);
            dp[1]=Math.max(dp[0],dp[1]);
            for(int i=2; i<dp.length; i++)
                dp[i]=Math.max(dp[i-1], dp[i-2]+dp[i]);
            answer = Math.max(answer, dp[dp.length-1]);
        }
        return answer;
    }
}