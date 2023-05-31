class Solution {
    public int solution(int n) {
        int answer = 1;
        int k;
        for(int i=2; i<n; i++){
            k =2*n-i*(i-1);
            if(k>0 && k%(2*i)==0)
                answer++;
        }
        return answer;
    }
}