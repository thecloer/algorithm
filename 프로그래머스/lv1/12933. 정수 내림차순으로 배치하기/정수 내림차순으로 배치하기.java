import java.util.*;
class Solution {
    public long solution(long n) {
        char[] a = Long.toString(n).toCharArray();
        Arrays.sort(a);
        long answer =0;
        for(int i=a.length-1; i>=0; i--)
            answer+=(a[i]-'0') * (long)Math.pow(10,i);
        
        return answer;
    }
}