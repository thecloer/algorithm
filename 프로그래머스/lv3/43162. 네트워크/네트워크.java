class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];
        for(int node=0; node<n; node++){
            if(!visited[node]){
                dfs(n, computers, visited, node);
                answer++;
            }
        }
        
        return answer;
    }
    void dfs(int n, int[][] computers, boolean[] visited, int node){
        visited[node] = true;
        for(int next=0; next<n; next++){
            if(!visited[next] && computers[node][next] == 1)
                dfs(n, computers, visited, next);
        }
    }
}