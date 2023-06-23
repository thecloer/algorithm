class Solution {
    public int solution(String dirs) {
        int answer = 0;
        int[] pos = {5, 5};
        boolean[][][] used = new boolean[2][11][11];
        
        for(char c:dirs.toCharArray()){
            int d = c=='L'||c=='R'? 0 : 1;
            int offset = c=='L'||c=='D'? -1 : 1;
            int next = pos[d]+offset;
            if(next<0 || next>10) continue;
            if(!used[d]
               [d==0?Math.min(pos[0], next): pos[0]]
               [d==1?Math.min(pos[1], next): pos[1]]){
                answer++;
                used[d]
               [d==0?Math.min(pos[0], next): pos[0]]
               [d==1?Math.min(pos[1], next): pos[1]] = true;
            }
            
            pos[d] = next;
        }
        return answer;
    }
}