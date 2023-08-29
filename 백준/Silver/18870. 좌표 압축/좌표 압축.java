import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        TreeMap<Integer,Integer> map = new TreeMap<>();
        int i = 0;
        for(; i<N; i++) {
            int n = Integer.parseInt(st.nextToken());
            map.put(n, 0);
            arr[i] = n;
        }

        i=0;
        for(int k:map.keySet())
            map.put(k, i++);
        
        for(i=0; i<N; i++){
            arr[i] = map.get(arr[i]);
        }

        StringBuilder ans = new StringBuilder();
        for(i=0; i<N; i++)
            ans.append(arr[i]).append(" ");
        System.out.println(ans);
	}
}