import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(String operation:operations) {
            char cmd = operation.charAt(0);
            int n = Integer.valueOf(operation.substring(2));
            
            if(cmd == 'I')
                map.merge(n, 1, Integer::sum);
            else if(cmd == 'D' && !map.isEmpty()){
                int key = (n==1) ? map.lastKey() : map.firstKey();
                int count = map.merge(key, -1, Integer::sum);
                if(count == 0) map.remove(key);
            }
        }

        int[] answer = new int[2];
        if(!map.isEmpty()){
            answer[0] = map.lastKey();
            answer[1] = map.firstKey();
        }
        return answer;
    }
}