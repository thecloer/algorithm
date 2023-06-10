class Solution {
    public int solution(String t, String p) {
        int answer = t.length() - p.length() + 1;
        for(int i=0; i<t.length() - p.length() + 1; i++){
            for(int j=0; j<p.length(); j++){
                if(t.charAt(i+j) > p.charAt(j)){
                    answer--;
                    break;
                } else if(t.charAt(i+j) < p.charAt(j)) 
                    break;
            }
        }
        return answer;
    }
}