import java.util.*;
class Solution {
    public String[] solution(String[] files) {
        return Arrays
            .stream(files)
            .map(File::new)
            .sorted()
            .map(f->f.name)
            .toArray(String[]::new);
    }
    
    class File implements Comparable<File> {
        String HEAD;
        int NUMBER;
        String TAIL;
        String name;
        File(String s){
            this.name = s;
            StringBuilder[] sb = new StringBuilder[3];
            for(int i=0; i<3; i++)
                sb[i] = new StringBuilder();
            sb[0].append(s.charAt(0));
            int p = 0;
            for(int i=1; i<s.length(); i++){
                char c = s.charAt(i);
                if(p<2 &&
                   (isNumber(c) && !isNumber(s.charAt(i-1)) || 
                   !isNumber(c) && isNumber(s.charAt(i-1))))
                    p++;
                sb[p].append(c);
            }
            this.HEAD = sb[0].toString();
            this.NUMBER = Integer.parseInt(sb[1].toString());
            this.TAIL = sb[2].toString();
        }
        private boolean isNumber(char c){
            return '0'<=c && c<='9';
        }
        
        @Override
        public int compareTo(File f){
            int h = this.HEAD.compareToIgnoreCase(f.HEAD);
            if(h!=0) return h;
            if(this.NUMBER != f.NUMBER) return this.NUMBER - f.NUMBER;
            return 0;
        }
    }
}