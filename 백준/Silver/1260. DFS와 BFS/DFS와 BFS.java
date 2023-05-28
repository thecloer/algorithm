import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int V = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] adjList = new ArrayList[N+1];
        for(int i=0; i<=N; i++)
            adjList[i] = new ArrayList<>();

        for(int i=1; i<=M; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            adjList[s].add(e);
            adjList[e].add(s);
        }
        for(int i=1; i<=N; i++)
            Collections.sort(adjList[i]);

        StringBuilder sb = new StringBuilder();
        boolean[] visited = new boolean[N+1];
        String dfsResult = dfs(sb, adjList, visited, V).toString();

        sb = new StringBuilder();
        visited = new boolean[N+1];
        String bfsResult = bfs(sb, adjList, visited, V).toString();

        System.out.println(dfsResult);
        System.out.println(bfsResult);
    }

    static StringBuilder dfs(StringBuilder sb, ArrayList<Integer>[] adjList, boolean[] visited, int curr){
        visited[curr] = true;
        sb.append(curr).append(" ");
        for(int i=0; i<adjList[curr].size(); i++){
            int next = adjList[curr].get(i);
            if(!visited[next])
                dfs(sb, adjList, visited, next);
        }
        return sb;
    }
    static StringBuilder bfs(StringBuilder sb, ArrayList<Integer>[] adjList, boolean[] visited, int curr){
        visited[curr] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(curr);
        visited[curr] = true;
        while(!queue.isEmpty()){
            curr = queue.poll();
            sb.append(curr).append(" ");
            for(int i=0; i<adjList[curr].size(); i++){
                int next = adjList[curr].get(i);
                if(!visited[next]){
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }
        return sb;
    }
}