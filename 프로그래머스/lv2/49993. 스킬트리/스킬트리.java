class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for(String tree:skill_trees){
            tree = tree.replaceAll(String.format("[^%s]",skill),"");
            if(tree.length()==0||(tree.charAt(0)==skill.charAt(0)&&skill.contains(tree))) answer++;
        }
        return answer;
    }
}