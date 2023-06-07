import java.util.*;
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String,Integer> map;
        dayLoop: for(int start=0; start<discount.length-9; start++){
            map = new HashMap();
            for(int i=0; i<10; i++)
                map.put(discount[start+i], map.getOrDefault(discount[start+i],0)+1);
            for(int i=0; i<want.length; i++)
                if(!map.containsKey(want[i]) || map.get(want[i])<number[i]) 
                    continue dayLoop;
            
            answer++;
        }
        return answer;
    }
}