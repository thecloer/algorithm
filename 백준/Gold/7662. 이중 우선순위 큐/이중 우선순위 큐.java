import java.util.*;
import java.io.*;

public class Main
{
    static PriorityQueue<Integer> minQ = new PriorityQueue<>();
    static PriorityQueue<Integer> maxQ = new PriorityQueue<>(Comparator.reverseOrder());
    static Map<Integer,Integer> countMap = new HashMap<>();
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.valueOf(br.readLine());
        for(int i=0; i<T; i++) {
            minQ.clear();
            maxQ.clear();
            countMap.clear();
            
            int k = Integer.valueOf(br.readLine());
            for(int j=0; j<k; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String operation = st.nextToken();
                int value = Integer.valueOf(st.nextToken());
                if("I".equals(operation)) {
                    countMap.put(value, countMap.getOrDefault(value, 0)+1);
                    minQ.offer(value);
                    maxQ.offer(value);
                } else if(value < 0) {
                    if(!minQ.isEmpty()){
                        int min = minQ.poll();
                        countMap.put(min, countMap.get(min)-1);
                    }
                } else {
                    if(!maxQ.isEmpty()){
                        int max = maxQ.poll();
                        countMap.put(max, countMap.get(max)-1);
                    }
                }
                cleanQs();
            }
            if(minQ.isEmpty() || maxQ.isEmpty())
                System.out.println("EMPTY");
            else {
                cleanQs();
                StringBuilder sb = new StringBuilder();
                sb.append(maxQ.peek())
                  .append(" ")
                  .append(minQ.peek());
                System.out.println(sb);
            }
        }
	}
    static void cleanQs() {
        while(!minQ.isEmpty() && countMap.get(minQ.peek()) == 0)
            minQ.poll();
        while(!maxQ.isEmpty() && countMap.get(maxQ.peek()) == 0)
            maxQ.poll();
    }
}