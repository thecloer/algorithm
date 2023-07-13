import java.util.*;
class Solution {
    public int solution(int b_length, int weight, int[] trucks) {
        int time = 1, totW = trucks[0];
        Queue<Integer> bridge = new LinkedList();
        for(int i=0; i<b_length-1; i++)
            bridge.add(0);
        bridge.add(trucks[0]);
        
        int nth = 1, onTheBridge = 1;
        while(onTheBridge>0){
            int polled = bridge.poll();
            if(polled>0){
                totW-=polled;
                onTheBridge--;
            }
            if(onTheBridge<b_length && nth<trucks.length && totW+trucks[nth] <= weight){
                bridge.add(trucks[nth]);
                totW+=trucks[nth++];
                onTheBridge++;
            } else 
                bridge.add(0);
            
            time++;
        }
        return time;
    }
}