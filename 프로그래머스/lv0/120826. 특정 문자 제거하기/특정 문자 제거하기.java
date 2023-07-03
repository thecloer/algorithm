class Solution {
    public String solution(String my_string, String letter) {
        return my_string.replaceAll(String.format("%s",letter),"");
    }
}