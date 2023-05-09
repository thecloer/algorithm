class Solution {
    public int solution(int n) {
        String a = Integer.toString(n, 3);
        String reversed = "";
        
        for(int i=a.length() -1; i >= 0; i--)
            reversed += a.charAt(i);
        
        return Integer.parseInt(reversed, 3);
    }
}