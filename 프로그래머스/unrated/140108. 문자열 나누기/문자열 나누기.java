class Solution {
    public int solution(String s) {
        int answer = 1;
        int[] count = new int[]{1,0};
        char start = s.charAt(0);
        for(int i=1; i<s.length(); i++){
            if(count[0] == count[1]){
                answer++;
                count = new int[]{1,0};
                start = s.charAt(i);
            } else 
                count[s.charAt(i) == start? 0: 1]++;
        }
        return answer;
    }
}