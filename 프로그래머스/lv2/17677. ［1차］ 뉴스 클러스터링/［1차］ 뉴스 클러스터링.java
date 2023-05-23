import java.util.*;
class Solution {
    private int MULTIPLE = 65536;
    public int solution(String str1, String str2) {
        HashMap<String,Integer> arr1 = splitWithLength(str1, 2);
        HashMap<String,Integer> arr2 = splitWithLength(str2, 2);
        
        if(arr1.size() == 0 && arr2.size() == 0) return MULTIPLE;
        int intersection = 0;
        int union = 0;
        
        Iterator<String> keySet1Iter = arr1.keySet().iterator();
        Set<String> keySet2 = arr2.keySet();
        String key;
        while(keySet1Iter.hasNext()){
            key = keySet1Iter.next();
            if(arr2.containsKey(key)){
                intersection += Math.min(arr1.get(key), arr2.get(key));
                union += Math.max(arr1.get(key), arr2.get(key));
                keySet2.remove(key);
            } else union += arr1.get(key);
        }
        
        Iterator<String> keySet2Iter = keySet2.iterator();
        while(keySet2Iter.hasNext())
            union += arr2.get(keySet2Iter.next());
        
        return (int)((double)intersection / union * MULTIPLE);
    }
    
    HashMap<String,Integer> splitWithLength(String s, int length){
        s = s.toLowerCase();
        HashMap<String,Integer> map = new HashMap();
        String key;
        for(int i=0; i<s.length()-1; i++){
            key = s.substring(i,i+length);
            if(key.matches("[a-z]*")) 
                map.put(key, map.getOrDefault(key,0) + 1);
        }
        return map;
    }
}