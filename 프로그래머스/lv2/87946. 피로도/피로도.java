class Solution {
    public int solution(int k, int[][] dungeons) {
        return dfs(k, dungeons, new boolean[dungeons.length]);
    }
    int dfs(int energe, int[][] dungeons, boolean[] visited){
        int count = 0;
        for(int i=0; i<dungeons.length; i++){
            if(visited[i] || energe<dungeons[i][0]) continue;
            visited[i] = true;
            count = Math.max(count, dfs(energe-dungeons[i][1],dungeons,visited)+1);
            visited[i] = false;
        }
        return count;
    }
}