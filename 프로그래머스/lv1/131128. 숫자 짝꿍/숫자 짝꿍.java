import java.util.*;
class Solution {
    public String solution(String X, String Y) {
        StringBuilder ans = new StringBuilder();
        int[] x = new int[10];
        int[] y = new int[10];
        for(char c:X.toCharArray())
            x[c-'0']++;
        for(char c:Y.toCharArray())
            y[c-'0']++;
        
        for(int i=9; i>=0; i--)
            for(int j=0, n=Math.min(x[i],y[i]); j<n; j++)
                ans.append(i);
        
        if(ans.length()==0)
            return "-1";
        if(ans.charAt(0)=='0')
            return "0";
        return ans.toString();
    }
}