import java.util.*;
class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        Map<Integer,Integer> before = new HashMap();
        Map<Integer,Integer> after = new HashMap();
        
        for(int i=0; i<topping.length; i++)
            after.put(topping[i],after.getOrDefault(topping[i],0)+1);
        
        for(int i=0; i<topping.length-1; i++){
            before.put(topping[i], before.getOrDefault(topping[i],0)+1);

            if(after.put(topping[i], after.get(topping[i])-1)==1)
                after.remove(topping[i]);
            
            if(after.keySet().size() == before.keySet().size())
                answer++;
            else if(after.keySet().size() < before.keySet().size())
                break;
        }
        return answer;
    }
}