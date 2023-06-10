class Solution {
    public String solution(String s, int n) {
        StringBuilder sb = new StringBuilder();
        for(char c:s.toCharArray())
            sb.append(shift(c,n));
        return sb.toString();
    }
    char shift(char c, int n){
        if(c>='a' && c<='z'){
            c += n;
            if(c>'z') c -= 26;
        } else if(c>='A' && c<='Z'){
            c += n;
            if(c>'Z') c -= 26;
        } 
        return c;  
    }
}