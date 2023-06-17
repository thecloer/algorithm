class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i=1; i<=number; i++){
            int n = getNumberOfDivisor(i);
            answer+= n>limit ? power : n;
        }
        return answer;
    }
    int getNumberOfDivisor(int n){
        int count=0;
        for(int i=1; i<Math.sqrt(n); i++)
            if(n%i==0) 
                count+=2;
        if(n%Math.sqrt(n)==0)
            count++;
        return count;
    }
}