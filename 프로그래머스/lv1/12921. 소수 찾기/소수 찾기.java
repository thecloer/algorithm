import java.util.*;
class Solution {
    public int solution(int n) {
        List<Integer> primes = new ArrayList();;
        boolean isPrime;
        for(int i=3; i<=n; i+=2){
            isPrime = true;
            for(int p=0; p<primes.size(); p++){
                if(primes.get(p)>Math.sqrt(i)) 
                    break;
                if(i%primes.get(p)==0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
                primes.add(i);
        }
        primes.add(2);
        return primes.size();
    }
}