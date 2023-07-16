class Solution {
    public int[] solution(int n) {
        int[] answer = new int[(n+1)/2];
        for(int i=1, k=0; i<=n; i+=2)
            answer[k++] = i;
        return answer;
    }
}