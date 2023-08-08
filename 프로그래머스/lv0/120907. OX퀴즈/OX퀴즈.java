class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        for(int i=0; i<quiz.length; i++){
            String[] tokens = quiz[i].split(" ");
            int result = tokens[1].equals("+") ?
                Integer.valueOf(tokens[0]) + Integer.valueOf(tokens[2]):
                Integer.valueOf(tokens[0]) - Integer.valueOf(tokens[2]);
            
            answer[i] = result == Integer.valueOf(tokens[4]) ? "O" : "X";
        }
        return answer;
    }
}