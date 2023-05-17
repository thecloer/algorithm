class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        int n;
        while(!s.equals("1")){
            answer[0]++;
            n = 0;
            for(char b:s.toCharArray()){
                if(b == '0') answer[1]++;
                else if(b == '1') n++;
            }
            s = Integer.toBinaryString(n);
        }
        return answer;
    }

}