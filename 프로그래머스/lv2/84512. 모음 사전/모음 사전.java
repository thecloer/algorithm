class Solution {
    public int solution(String word) {
        final String LETTERS = "AEIOU";
        int n = LETTERS.length();
        double tot = (Math.pow(n,n+1)-n)/(n-1);
        int answer = 0;
        for(char c:word.toCharArray())
            answer += LETTERS.indexOf(c) * (tot/=n) + 1;
        return answer;
    }
}