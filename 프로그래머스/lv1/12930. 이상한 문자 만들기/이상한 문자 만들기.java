class Solution {
    public String solution(String s) {
        boolean isUpperCase = true;
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c == ' ') isUpperCase = true;
            else {
                if(isUpperCase) c=Character.toUpperCase(c);
                else c=Character.toLowerCase(c);
                isUpperCase = !isUpperCase;
            }
            sb.append(c);
        }
        return sb.toString();
    }
}