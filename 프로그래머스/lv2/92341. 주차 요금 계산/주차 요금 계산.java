import java.util.*;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String,Integer> map = new TreeMap();
        for(String record: records){
            String[] rArr = record.split(" ");
            int time = rArr[2].equals("IN") ? -1 : 1;
            time *= parseTime(rArr[0]);
            map.put(rArr[1], map.getOrDefault(rArr[1], 0)+time);
        }
        int[] answer = new int[map.size()];
        int i=0;
        for(int time: map.values()){
            if(time<=0) time += parseTime("23:59");
            time -= fees[0];
            int cost = fees[1];
            if(time>0)
                cost+=fees[3]*(time/fees[2] + (time%fees[2] > 0 ? 1 : 0));
            answer[i++] = cost;
        }
        return answer;
    }
    int parseTime(String time){
        String[] timeStrings = time.split(":");
        return 60*Integer.parseInt(timeStrings[0]) + Integer.parseInt(timeStrings[1]);
    }
}