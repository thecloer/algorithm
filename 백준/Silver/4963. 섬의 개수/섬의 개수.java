import java.io.*;
import java.util.*;
public class Main {
    static private int w, h;
    static private int[][] map;
    static private boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        while(true){
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            if(w==0 && h==0) break;
            map = new int[h][w];
            visited = new boolean[h][w];
            for(int col=0; col<h; col++) {
                st = new StringTokenizer(br.readLine());
                for (int row = 0; row < w; row++)
                    map[col][row] = Integer.parseInt(st.nextToken());
            }
            int count = 0;
            for(int col=0; col<h; col++)
                for(int row=0; row<w; row++)
                    if(!visited[col][row] && map[col][row] == 1 && dfs(col,row)>0)
                        count++;
            sb.append(count).append("\n");
        }

        System.out.print(sb);
    }
    private static int dfs(int col, int row){
        visited[col][row] = true;
        int nextCol;
        int nextRow;

        int result = 1;
        for(int i=-1; i<2; i++){
            nextCol = col + i;
            for (int j=-1; j<2; j++) {
                nextRow = row + j;

                if (nextCol >= 0 && nextCol < h
                        && nextRow >= 0 && nextRow < w
                        && !visited[nextCol][nextRow]
                        && map[nextCol][nextRow] == 1) {
                    result += dfs(nextCol, nextRow);
                }
            }
        }
        return result;
    }
}
