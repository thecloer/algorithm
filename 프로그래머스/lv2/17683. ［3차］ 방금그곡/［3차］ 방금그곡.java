class Solution {
    public String solution(String m, String[] musicinfos) {
        m = removeSharp(m);
        String title = null;
        int savedPlayTime = 0;
        for(String musicInfo:musicinfos){
            String[] info = musicInfo.split(",");
            info[3] = removeSharp(info[3]);
            int playTime = getTimeDiff(info[0], info[1]);
            
            StringBuilder played = new StringBuilder();
            for(int time=0; time<playTime; time++)
                played.append(info[3].charAt(time%info[3].length()));
            
            if(played.toString().contains(m) 
               && (title==null || savedPlayTime<playTime)) {
                title = info[2];
                savedPlayTime = playTime;
            }
        }
        return title==null? "(None)" : title;
    }
    int getTimeDiff(String start, String end){
        return 60 * (Integer.valueOf(end.substring(0,2))
                   - Integer.valueOf(start.substring(0,2)))
               + Integer.valueOf(end.substring(3,5))
               - Integer.valueOf(start.substring(3,5));
    }
    String removeSharp(String music){
        StringBuilder sb = new StringBuilder();
        char last = ' ';
        int len = 0;
        for(char c:music.toCharArray()){
            if(c=='#'){
                sb.setCharAt(len-1, Character.toLowerCase(last));
            } else {
                sb.append(c);
                last = c;
                len++;
            }
        }
        return sb.toString();
    }
}