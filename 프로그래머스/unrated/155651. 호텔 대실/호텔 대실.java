import java.util.*;
class Solution {
    public int solution(String[][] book_time) {
        int[][] reservations = new int[book_time.length][];
        for(int i=0; i<reservations.length; i++){
            reservations[i] = new int[] {timeToMinutes(book_time[i][0]),
                                         timeToMinutes(book_time[i][1])};
        }
        Arrays.sort(reservations, (t1,t2)->t1[0]-t2[0]);
        
        int answer = 0;
        PriorityQueue<Integer> timeWindow = new PriorityQueue();
        for(int[] reservation:reservations){
            while(!timeWindow.isEmpty() && timeWindow.peek()<=reservation[0])
                timeWindow.poll();
            timeWindow.offer(reservation[1]+10);
            answer = Math.max(answer, timeWindow.size());
        }
        return answer;
    }
    int timeToMinutes(String time){
        String[] splited = time.split(":");
        return 60*Integer.valueOf(splited[0])+Integer.valueOf(splited[1]);
    }
}