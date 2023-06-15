class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int p0=0, p1=0, p2=0;
        while(p0<goal.length){
            if(p1<cards1.length && goal[p0].equals(cards1[p1])){
                p0++;
                p1++;
            } else if(p2<cards2.length && goal[p0].equals(cards2[p2])){
                p0++;
                p2++;
            } else break;
        }
        return p0 == goal.length ? "Yes" : "No";
    }
}