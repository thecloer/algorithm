class Solution {
    public int solution(int k, int[][] dungeons) {
        boolean[] visited = new boolean[dungeons.length];
        return dfs(k, dungeons, visited);
    }
    int dfs(int energe, int[][] dungeons, boolean[] visited){
        if(energe<0) return 0;
        int count = 0;
        for(int i=0; i<dungeons.length; i++){
            if(!visited[i] && energe>=dungeons[i][0]){
                visited[i] = true;
                count = Math.max(count, dfs(energe-dungeons[i][1],dungeons,visited)+1);
                visited[i] = false;
            }
        }
        return count;
    }
}