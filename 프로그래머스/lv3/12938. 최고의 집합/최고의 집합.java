class Solution {
    public int[] solution(int n, int s) {
        if(n>s) return new int[]{-1};
        int[] answer = new int[n];
        for(int i=0; i<answer.length; i++)
            answer[i] = s/n + (answer.length-i<=s%n?1:0);
        return answer;
    }
}