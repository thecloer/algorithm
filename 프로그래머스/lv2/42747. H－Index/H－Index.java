import java.util.*;
class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int i = 1;
        for(;i <= citations.length; i++)
            if(citations[citations.length-i] < i) 
                break;
        
        return i-1;
    }
}