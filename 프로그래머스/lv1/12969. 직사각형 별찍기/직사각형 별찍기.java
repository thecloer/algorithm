import java.io.*;
import java.util.*;


class Solution {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int width = Integer.parseInt(st.nextToken());
        int heigth = Integer.parseInt(st.nextToken());
        
        StringBuilder sb = new StringBuilder();
        for(int row=0; row<heigth; row++){
            for(int col=0; col<width; col++)
                sb.append("*");
            sb.append("\n");
        }
        System.out.println(sb);
    }
}