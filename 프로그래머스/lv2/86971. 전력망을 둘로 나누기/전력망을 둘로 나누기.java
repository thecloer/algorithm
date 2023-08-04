class Solution {
    public int solution(int n, int[][] wires) {
        int[] neighbors = new int[n+1];
        
        int root = 0;
        for(int[] wire:wires)
            for(int node:wire)
                neighbors[node]++;
        for(int i=1; i<=n; i++)
            root = Math.max(root, neighbors[i]);
        
        int[] counts = new int[n+1];
        dfs(wires, new boolean[wires.length], counts, root);
        
        int answer = n;
        for(int count:counts)
            answer = Math.min(answer, Math.abs(n-2*count));
        
        return answer;
    }
    void dfs(int[][] wires, boolean[] used, int[] counts, int node){
        for(int i=0; i<wires.length; i++){
            if(used[i]) continue;
            for(int j=0; j<2; j++){
                if(wires[i][j]==node){
                    used[i]=true;
                    int child = wires[i][(j+1)%2];
                    dfs(wires, used, counts, child);
                    counts[node]+=counts[child];
                    break;
                }
            }
        }
        counts[node]++;
    }
}