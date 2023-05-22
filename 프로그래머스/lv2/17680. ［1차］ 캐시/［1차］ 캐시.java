import java.util.*;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        Cache cache = new Cache(cacheSize);
        for(String city: cities)
            cache.get(city);
        return cache.getTime();
    }
}


class Cache {
    private int size;
    private int time = 0;
    private LinkedList<String> cache = new LinkedList();
    Cache(int size) {
        this.size = size;
    }
    private void checkSize(){
        if(cache.size() > size){
            cache.remove(size);
            checkSize();
        }
    }
    void get(String item){
        item = item.toLowerCase();
        int i = cache.indexOf(item);
        if(i > -1) {
            cache.remove(i);
            time += 1;
        }
        else time += 5;
        cache.add(0, item);
        checkSize();
    }
    int getTime(){
        return time;
    }
}