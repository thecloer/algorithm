class Solution {
    final String LETTERS = "AEIOU";
    public int solution(String word) {
        int count =0;
        return dfs(word,0,new StringBuilder());
    }
    int dfs(String word, int count, StringBuilder sb){
        for(int i=0; i<LETTERS.length(); i++){
            sb.append(LETTERS.charAt(i));
            count++;
            if(word.equals(sb.toString())) 
                break;
            if(sb.length()<5)
                count = dfs(word, count, sb);
            if(word.equals(sb.toString())) 
                break;
            sb.deleteCharAt(sb.length()-1);
        }
        return count;
    }
}