import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int[] score = new int[3];
        int scoreIdx = -1;
        for(int i=0; i<dartResult.length(); i++){
            char c = dartResult.charAt(i);
            int numeric = Character.getNumericValue(c);
            if(numeric>=0 && numeric<10){
                if(c=='0' && i>0 && dartResult.charAt(i-1)=='1') score[scoreIdx] = 10;
                else score[++scoreIdx] = numeric;
            } else if(c=='D') score[scoreIdx] = (int)Math.pow((double)score[scoreIdx],2);
            else if(c=='T') score[scoreIdx] = (int)Math.pow((double)score[scoreIdx],3);
            else if(c=='*'){
                score[scoreIdx] *= 2;
                if(scoreIdx>0) score[scoreIdx-1] *= 2;
            } else if(c=='#') score[scoreIdx] *= -1;
        }
        
        int sum = 0;
        for(int i=0; i<3; i++)
            sum+=score[i];
        
        return sum;
    }
}
