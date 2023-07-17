import java.util.*;
class Solution {
    public String[] solution(String[] orders, int[] course) {
        Map<String,Integer>[] maps = new HashMap[course.length];
        for(int i=0; i<maps.length; i++)
            maps[i] = new HashMap();
        
        for(String o:orders){
            char[] order = o.toCharArray();
            Arrays.sort(order);
            for(int i=0; i<course.length; i++){
                if(course[i]>order.length)
                    break;
                makeCourse(maps[i], new StringBuilder(), order, 0, course[i]);
            }
        }
        
        ArrayList<String> answer = new ArrayList();
        for(int i=0; i<maps.length; i++){
            int max=2;
            Set<String> keys = maps[i].keySet();
            for(String key:keys)
                max = Math.max(maps[i].get(key), max);
            for(String key:keys)
                if(maps[i].get(key)==max)
                    answer.add(key);
        }
        
        Collections.sort(answer);
        return answer.toArray(new String[answer.size()]);
    }
    
    void makeCourse(Map<String,Integer> map, StringBuilder course, char[] order, int start, int count){
        if(count==0){
            String c = course.toString();
            map.put(c,map.getOrDefault(c,0)+1);
            return;
        }
        for(int i=start; i<order.length+1-count; i++){
            course.append(order[i]);
            makeCourse(map, course, order, i+1, count-1);
            course.deleteCharAt(course.length()-1);
        }
    }
}