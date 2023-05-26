class Solution {
    public int solution(int n, int k) {
        String s = transform(n, k);
        return countPrimes(s);
    }
    
    String transform(int n, int k){
        String result = "";
        while(n > 0){
            result = n%k + result;
            n /= k;
        }
        return result;
    }
    
    int countPrimes(String s){
        int count = 0;
        s = s.replaceAll("^0+|0+$","").replaceAll("0+","0");
        System.out.println(s);
        if(s.equals("")) return 0;
        for(String n:s.split("0"))
            if(isPrime(Long.parseLong(n))) 
                count++;
        
        return count;
    }
    
    boolean isPrime(long n){
        if(n==2) return true;
        if(n<2||n%2==0) return false;
        for(int i=3; i<=(long)Math.sqrt(n); i+=2)
            if(n%i==0) return false;
        return true;
    }
}