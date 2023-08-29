import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            int k = Integer.parseInt(br.readLine());
            TreeMap<Integer, Integer> map = new TreeMap<>();
            while(k-- > 0) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                char cmd = st.nextToken().charAt(0);
                int n = Integer.parseInt(st.nextToken());

                if(cmd == 'I') 
                    map.merge(n, 1, Integer::sum);
                else if(cmd == 'D' && !map.isEmpty()){
                    int key = (n==1) ? map.lastKey() : map.firstKey();
                    int count = map.merge(key, -1, Integer::sum);
                    if(count == 0) map.remove(key);
                }
            }

            if(map.isEmpty()) 
                System.out.println("EMPTY");
            else {
                StringBuilder ans = new StringBuilder();
                ans.append(map.lastKey()).append(" ").append(map.firstKey());
                System.out.println(ans);
            }
        }
	}
}