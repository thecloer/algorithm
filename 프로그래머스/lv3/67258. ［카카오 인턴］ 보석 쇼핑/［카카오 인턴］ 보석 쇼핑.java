import java.util.*;
class Solution {
    public int[] solution(String[] gems) {
        Map<String, Integer> map = new HashMap();
        for(String gem:gems)
            map.put(gem, 0);
        
        int kinds = map.size();
        map.clear();
        int[] answer = {1, gems.length};
        for(int left=0, right=0; right<gems.length; right++){
            map.put(gems[right], map.getOrDefault(gems[right],0)+1);
            
            while(map.size()==kinds && left<right && map.get(gems[left])>1)
                map.put(gems[left], map.get(gems[left++])-1);
            
            if(map.size()==kinds && right-left<answer[1]-answer[0]){
                answer[0] = left+1;
                answer[1] = right+1;
            }
        }
        return answer;
    }
}