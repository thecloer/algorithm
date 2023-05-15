import java.util.*;
class Solution {
    public Integer[] solution(String today, String[] terms, String[] privacies) {
        LinkedHashSet<Integer> answer = new LinkedHashSet();
        HashMap<String,Integer> termMap = new HashMap();
        for(int i=0; i<terms.length; i++){
            String[] t = terms[i].split(" ");
            termMap.put(t[0],Integer.parseInt(t[1]));
        }
        
        for(int i=0; i<privacies.length; i++){
            String[] p = privacies[i].split(" ");
            Day privacy = new Day(p[0]);
            privacy.addMonth(termMap.get(p[1]));
            if(privacy.dDay(today) <= 0)
                answer.add(i+1);
        }
        
        return answer.toArray(new Integer[0]);
    }
    
    private class Day {
        private int[] day;
        Day(String yyyymmdd){
            this.day= stringToDayArray(yyyymmdd);
        }
        private int[] stringToDayArray(String yyyymmdd){
            return Arrays.stream(yyyymmdd.split("\\.")).map(i->Integer.parseInt(i)).mapToInt(i->i).toArray();
        }
        void addMonth(int month){
            if(day[1]+month>12){
                day[0] += (day[1] + month) / 12;
                day[1] = (day[1] + month) % 12;
            }
            else day[1] += month;
        }
        int dDay(String yyyymmdd){
            int[] today = stringToDayArray(yyyymmdd);
            return 28*12*(day[0]-today[0]) + 28*(day[1]-today[1]) + (day[2]-today[2]);
        }
    }
}