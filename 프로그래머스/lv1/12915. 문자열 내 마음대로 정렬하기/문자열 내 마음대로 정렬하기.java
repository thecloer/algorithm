import java.util.*;
class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings,(a,b)->{
            int diff = a.charAt(n)-b.charAt(n);
            if(diff==0) return a.compareTo(b);
            return diff;
        });
        return strings;
    }
}