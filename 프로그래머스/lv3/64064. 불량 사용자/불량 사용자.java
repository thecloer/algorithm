import java.util.*;
class Solution {
    Set<String> result = new HashSet();
    public int solution(String[] user_id, String[] banned_id) {
        List<String>[] candidates = new ArrayList[banned_id.length];
        Arrays.setAll(candidates, (i) -> new ArrayList());
        
        for(int i=0; i<banned_id.length; i++)
            for(String user:user_id)
                if(user.matches(banned_id[i].replace("*",".")))
                    candidates[i].add(user);

        countCases(candidates, new TreeSet(), 0);
        return result.size();
    }
    void countCases(List<String>[] candidates, Set<String> used, int cIdx){
        if(cIdx==candidates.length){
            result.add(used.toString());            
            return;
        }
        for(int i=0; i<candidates[cIdx].size(); i++){
            String user = candidates[cIdx].get(i);
            if(used.add(user)){
                countCases(candidates, used, cIdx+1);
                used.remove(user);
            }
        }
    }
}