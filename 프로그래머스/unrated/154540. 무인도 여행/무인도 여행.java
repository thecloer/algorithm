import java.util.*;
class Solution {
    int[][] MOVE = {{-1,0},{1,0},{0,-1},{0,1}};
    public int[] solution(String[] maps) {
        int[][] map = new int[maps.length][];
        for(int i=0; i<map.length; i++){
            map[i] = new int[maps[i].length()];
            for(int j=0; j<map[i].length; j++){
                char c = maps[i].charAt(j);
                map[i][j] = c=='X'? 0 : Character.getNumericValue(c);
            }
        }
        
        ArrayList<Integer> list = new ArrayList();
        for(int i=0; i<map.length; i++)
            for(int j=0; j<map[i].length; j++)
                if(map[i][j]>0)
                    list.add(dfs(map, i, j));
        
        if(list.size()==0)
            return new int[]{-1};
        
        Collections.sort(list);
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++)
            answer[i] = list.get(i);
        return answer;
    }
    
    int dfs(int[][] map, int x, int y){
        int acc = map[x][y];
        map[x][y]=0;
        int[] next;
        for(int[] m:MOVE){
            next = new int[]{x, y};
            for(int i=0; i<2; i++)
                next[i] += m[i];
                        
            if(next[0]>=0 && next[0]<map.length
              && next[1]>=0 && next[1]<map[next[0]].length
              && map[next[0]][next[1]] > 0)
                acc+=dfs(map, next[0], next[1]);
        }
        return acc;
    }
}