import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        Map<String,String> nicknames = new HashMap();
        for(String r:record){
            String[] arr = r.split(" ");
            if(arr[0].equals("Change") || arr[0].equals("Enter"))
                nicknames.put(arr[1], arr[2]);
        }
        
        List<String> messages = new LinkedList();
        for(String r:record){
            String[] arr = r.split(" ");
            if(arr[0].equals("Change")) continue;
            StringBuilder sb = new StringBuilder();
            sb.append(nicknames.get(arr[1]));
            if(arr[0].equals("Enter"))
                sb.append("님이 들어왔습니다.");
            else if(arr[0].equals("Leave"))
                sb.append("님이 나갔습니다.");
            messages.add(sb.toString());
        }
        return messages.toArray(String[]::new);
    }
}