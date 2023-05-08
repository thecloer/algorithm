import java.util.*;

class Solution {
    HashSet<Integer> combs = new HashSet();
    
    public int solution(String numbers) {
        int answer = 0;
        combination("", numbers);
        
        Iterator<Integer> iter = combs.iterator();
        while(iter.hasNext())
            if(isPrime(iter.next()))
                answer++;
        
        return answer;
    }
    
    public void combination(String prev, String others){
        if(!prev.equals(""))
            combs.add(Integer.valueOf(prev));
        
        for(int i=0; i<others.length(); i++)
            combination(prev+others.charAt(i), others.substring(0,i)+others.substring(i+1));
    }
    
    public boolean isPrime(Integer number){
        if(number == 2)
            return true;
        
        if(number == 0 || number == 1 || number % 2 == 0)
            return false;
        
        for(int i=3; i<=(int)Math.sqrt(number); i+=2)
            if(number % i == 0)
                return false;
        
        return true;
    }
}