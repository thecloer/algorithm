class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        Billboard board = new Billboard(k);
        for(int i=0; i<score.length; i++){
            board.add(score[i]);
            answer[i] = board.peek();
        }
        return answer;
    }
    
    class Billboard{
        private int[] scores;
        private int head;
        Billboard(int size){
            this.scores = new int[size];
            this.head = size;
        }
        void add(int score){
            int index = getIndex(score);
            if(head == 0){
                if(index<0) return;
                for(int i=scores.length-1; i>index; i--)
                    copy(i-1, i);
            } else {
                if(index==-1) index = scores.length-1;
                else index--;
                head--;
                for(int i=head; i<index; i++)
                    copy(i+1, i);
            }
            scores[index] = score;
        }
        int peek(){
            return scores[scores.length-1];
        }
        private int getIndex(int score){
            for(int i=head; i<scores.length; i++)
                if(score>scores[i])
                    return i;
            return -1;
        }
        private void copy(int from, int to){
            if(to>=0&&to<scores.length && from>=0&&from<scores.length && from!=to)
                scores[to] = scores[from];       
        }
    }
}