import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        HashMap<String, HashSet<String>> reportedMap = new HashMap();
        
        for(String r: report){
            String[] rArray = r.split(" ");
            HashSet<String> reporters = reportedMap.getOrDefault(rArray[1], new HashSet<String>());
            reporters.add(rArray[0]);
            reportedMap.put(rArray[1], reporters);
        }
        
        Iterator<String> iterReported = reportedMap.keySet().iterator();
        while(iterReported.hasNext()){
            String reported = iterReported.next();
            if(reportedMap.get(reported).size() >= k){
                Iterator<String> reporters = reportedMap.get(reported).iterator();
                while(reporters.hasNext())
                    answer[Arrays.asList(id_list).indexOf(reporters.next())] += 1;
            }
        }
        
        return answer;
    }
}