import java.util.*;
class Solution {
    public long[] solution(long k, long[] room_number) {
        Map<Long, Long> map = new HashMap();
        long[] answer = new long[room_number.length];
        for(int i=0; i<room_number.length; i++){
            long room = room_number[i];
            if(map.containsKey(room)){
                LinkedList<Long> list = new LinkedList();
                do {
                    list.add(room);
                    room = map.get(room);
                } while(map.containsKey(room));
                for(long r:list)
                    map.put(r, room+1);
            } 
            map.put(room, room+1);
            answer[i] = room;
        }   
        return answer;
    }
}