class Solution {
    public String solution(String s) {
        String answer = "";
        char[] letters = s.toLowerCase().toCharArray();
        boolean upper = true;
        for(char letter:letters){
            answer += upper ? Character.toUpperCase(letter) : letter;
            upper = letter == ' ';
        }
        return answer;
    }
}