import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> map = new HashMap();
        
        for(String[] cloth:clothes)         
            map.put(cloth[1], map.getOrDefault(cloth[1],0) + 1);
        
        Iterator<String> keys = map.keySet().iterator();
        while(keys.hasNext())
            answer *= map.get(keys.next()) + 1;
        
        
        return answer - 1;
    }
}