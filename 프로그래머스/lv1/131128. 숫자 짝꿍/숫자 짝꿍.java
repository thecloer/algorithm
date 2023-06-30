import java.util.*;
class Solution {
    public String solution(String X, String Y) {
        Map<Character, Integer> mapX = new HashMap();
        Map<Character, Integer> mapY = new HashMap();
        for(char c:X.toCharArray())
            mapX.put(c,mapX.getOrDefault(c,0)+1);
        for(char c:Y.toCharArray())
            mapY.put(c,mapY.getOrDefault(c,0)+1);
        
        Set<Character> inter = mapX.keySet();
        inter.retainAll(mapY.keySet());
        if(inter.size()==0)
            return "-1";
        if(inter.size()==1 && inter.contains('0'))
            return "0";
        
        Set<Character> iterSet = new TreeSet<>((c1,c2)->c2.compareTo(c1));
        iterSet.addAll(inter);
        Iterator<Character> iter = iterSet.iterator();
        StringBuilder sb = new StringBuilder();
        while(iter.hasNext()){
            char c = iter.next();
            for(int i=0, n=Math.min(mapX.get(c),mapY.get(c)); i<n; i++)
                sb.append(c);
        }
        return sb.toString();
    }
}