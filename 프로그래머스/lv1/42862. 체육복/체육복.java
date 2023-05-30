import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        n -= lost.length;
        Arrays.sort(lost);
        Arrays.sort(reserve);
        for(int i=0; i<lost.length; i++){
            for(int j=0; j<reserve.length; j++){
                if(lost[i] == reserve[j]){
                    lost[i] = -1;
                    reserve[j] = -1;
                    n++;
                    break;
                } 
            }
        }
        for(int i=0; i<lost.length; i++){
            for(int j=0; j<reserve.length; j++){
                if(lost[i] == reserve[j]-1 || lost[i] == reserve[j]+1){
                    reserve[j] = -1;
                    n++;
                    break;
                }
            }
        }
                    
        return n;
    }
}