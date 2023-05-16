import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        // Map<신고당한 사람, Set<신고한사람>>
        // report 순회하며  Map 완성
        // Map 순회하며 신고 한 사람 > k면 정지, 신고한사람 result +1
        int[] answer = new int[id_list.length];
        HashMap<String, HashSet<String>> reportedMap = new HashMap();
        
        for(String r: report){
            String[] rArray = r.split(" ");
            HashSet<String> reporters = reportedMap.getOrDefault(rArray[1], new HashSet<String>());
            reporters.add(rArray[0]);
            reportedMap.put(rArray[1], reporters);
        }
        
        Iterator<Map.Entry<String,HashSet<String>>> entries = reportedMap.entrySet().iterator();
        while(entries.hasNext()){
            Map.Entry<String,HashSet<String>> entry = entries.next();
            if(entry.getValue().size() >= k){
                Iterator<String> reporters = entry.getValue().iterator();
                while(reporters.hasNext())
                    answer[Arrays.asList(id_list).indexOf(reporters.next())] += 1;
            }
        }
        
        return answer;
    }
}