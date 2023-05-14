class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        String keys = "147*2580369#";
        int[][] fingPos = {{0,3},{2,3}};
        boolean isRight = true;
        for(int n:numbers){
            int i = keys.indexOf((char)('0' + n));
            if(i/4 == 0) isRight = false;
            else if(i/4 == 2) isRight = true;
            else if(i/4 == 1){
                int diff = Math.abs(i%4 - fingPos[0][1]) + (fingPos[0][0] == 1?0:1)
                         - (Math.abs(i%4 - fingPos[1][1]) + (fingPos[1][0] == 1?0:1));
                if(diff < 0) isRight = false;
                else if(diff > 0) isRight = true;
                else isRight = hand.equals("right");
            }
                
            answer += isRight ? "R" : "L";
            fingPos[isRight?1:0][0] = i/4;
            fingPos[isRight?1:0][1] = i%4;
        }
        
        return answer;
    }
}