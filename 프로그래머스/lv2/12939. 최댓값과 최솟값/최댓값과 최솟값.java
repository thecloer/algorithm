class Solution {
    public String solution(String s) {
        String[] strArray = s.split(" ");
        int minIdx = 0;
        int maxIdx = 0;
        for(int i=0; i<strArray.length; i++){
            if(Integer.parseInt(strArray[i])<Integer.parseInt(strArray[minIdx]))
                minIdx = i;
            else if(Integer.parseInt(strArray[i])>Integer.parseInt(strArray[maxIdx]))maxIdx = i;
        }
        
        return strArray[minIdx] + " " + strArray[maxIdx];
    }
}