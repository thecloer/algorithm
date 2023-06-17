class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        int right = 0;
        for(int s:section){
            if(right<s) {
                answer++;
                right = s + m - 1;
            } 
            if(right>n) break;
        }        
        return answer;
    }
}