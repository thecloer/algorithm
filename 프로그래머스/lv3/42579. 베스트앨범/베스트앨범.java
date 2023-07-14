import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Genre> playListMap = new HashMap();
        for(int i=0; i<genres.length; i++)
            playListMap.put(genres[i], 
                         playListMap.getOrDefault(genres[i], new Genre(genres[i]))
                         .addSong(i, plays[i]));
        
        Genre[] playListArray = playListMap.values().stream()
            .sorted()
            .toArray(Genre[]::new);
        
        ArrayList<Integer> answer = new ArrayList();
        for(Genre g:playListArray){
            for(int i=0; i<2; i++){
                int id = g.getTopSong();
                if(id<0) continue;
                answer.add(id);
            }
        }
        return answer.stream().mapToInt(i->i).toArray();
    }
    class Genre implements Comparable<Genre> {
        private String genre;
        private int count = 0;
        private PriorityQueue<Song> list = new PriorityQueue();
        Genre(String genre){
            this.genre = genre;
        }
        Genre addSong(int id, int playCount){
            count+=playCount;
            list.add(new Song(id, playCount));
            return this;
        }
        int getTopSong(){
            return list.size() == 0 ? -1 :  list.poll().getId();
        }
        int getCount(){
            return count;
        }
        @Override
        public int compareTo(Genre g){
            return g.getCount() - count;
        }
    }
    class Song implements Comparable<Song> {
        private int id, count;
        Song(int id, int count){
            this.id=id;
            this.count=count;
        }
        int getId(){
            return id;
        }
        int getCount(){
            return count;
        }
        @Override
        public int compareTo(Song s){
            int countDiff = s.getCount() - count;
            return countDiff == 0 ? id - s.getId() : countDiff;
        }
    }
}