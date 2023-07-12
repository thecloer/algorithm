class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        for(int i=0; i<numbers.length; i++){      
            long n = numbers[i];
            if((n&1)==0){
                answer[i] = n + 1;
                continue;
            }
                
            long m = 1;
            while((n & m) > 0)
                m <<= 1;

            answer[i] = m>n ? n+1+(n>>1) : (n|m)&(~(m>>1));
        }
        return answer;
    }
}