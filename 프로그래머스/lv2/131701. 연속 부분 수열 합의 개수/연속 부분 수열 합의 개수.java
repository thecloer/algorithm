import java.util.*;
class Solution {
    public int solution(int[] elements) {
        Set<Integer> set = new HashSet();
        int sum;
        for(int i=0; i<elements.length; i++){
            sum = elements[i];
            set.add(sum);
            for(int j=1; j<elements.length-1; j++){
                sum+=elements[(j+i)%elements.length];
                set.add(sum);
            }
        }
        
        return set.size() + 1;
    }
}