class Solution {
    boolean solution(String s) {
        s=s.toLowerCase();
        int a = 0;
        for(char c:s.toCharArray()){
            if(c=='p') a++;
            else if(c=='y') a--;
        }

        return a==0;
    }
}