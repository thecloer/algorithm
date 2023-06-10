import java.util.*;
class Solution {
    public int solution(int[] d, int budget) {
        Arrays.sort(d);
        int count = 0;
        for(; count<d.length; count++){
            if(budget<d[count]) break;
            else budget -= d[count];
        }
        return count;
    }
}