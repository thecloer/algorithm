import java.util.*;

class Solution {
    LinkedHashSet<Integer> set = new LinkedHashSet<>();
    
    public Integer[] solution(int n) {    
        int m = checkAndDivide(n, 2);
            
        for(int i = 3; i <= n; i += 2)
            m = checkAndDivide(m, i);
        
        return set.toArray(new Integer[set.size()]);
    }
    
    public int checkAndDivide(int n, int i){
        if(n % i != 0) return n;
        
        set.add(i);
        while(n % i == 0)
            n /= i;
        
        return n;
    }
}