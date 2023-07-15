class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        int i = 0;
        while(k>0 && i<sb.length()-1){
            if(sb.charAt(i)<sb.charAt(i+1)){                
                sb.deleteCharAt(i);
                k--;
                if(i>0)
                    i--;
            } else
                i++;
        }
        if(k>0)
            sb.setLength(sb.length()-k);
        return sb.toString();
    }
}