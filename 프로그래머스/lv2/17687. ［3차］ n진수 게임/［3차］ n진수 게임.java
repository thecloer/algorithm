class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        int turn = 0;
        int num = 0;
        game: while(true){
            for(char c:Integer.toString(num++,n).toCharArray()){
                if(turn++ % m == p - 1) answer+=c;
                if(turn >= m*(t-1)+p) break game;
            }
        }
        return answer.toUpperCase();
    }
}