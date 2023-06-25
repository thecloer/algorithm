class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for(String tree:skill_trees){
            tree = tree.replaceAll(String.format("[^%s]",skill),"");
            if(skill.indexOf(tree) == 0)
                answer++;
        }
        return answer;
    }
}