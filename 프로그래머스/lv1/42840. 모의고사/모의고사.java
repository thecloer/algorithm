import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        Student[] students = {
            new Student(new int[]{1, 2, 3, 4, 5}),
            new Student(new int[]{2, 1, 2, 3, 2, 4, 2, 5}),
            new Student(new int[]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5})
            };
        for(int i=0; i<answers.length; i++)
            for(Student student: students)
                if(student.solved(i, answers[i]))
                    student.addScore(1);
        
        int max = 0;
        for(int i=1; i<students.length; i++)
            if(students[i].getScore() > students[max].getScore())
                max = i;
        
        List<Integer> answer = new LinkedList();
        for(int i=max; i<students.length; i++)
            if(students[i].getScore() == students[max].getScore())
                answer.add(i+1);
        
        return answer.stream().mapToInt(i->i).toArray();
    }
    
    class Student{
        private int[] rule;
        private int score = 0;
        Student(int[] rule){
            this.rule=rule;
        }
        boolean solved(int num, int answer){
            return answer==rule[num%rule.length];
        }
        void addScore(int score){
            this.score+=score;
        }
        int getScore(){
            return score;
        }
    }
}