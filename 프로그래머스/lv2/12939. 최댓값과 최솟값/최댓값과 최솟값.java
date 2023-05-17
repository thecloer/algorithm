class Solution {
    public String solution(String s) {
        String[] strArray = s.split(" ");
        int min, max, n;
        min = max = Integer.parseInt(strArray[0]);
        for(String str:strArray){
            n = Integer.parseInt(str);
            if(n < min) min = n;
            else if(n > max) max = n;
        }
        
        return min + " " + max;
    }
}