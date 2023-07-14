import java.util.*;
class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Queue<Integer> q = new LinkedList();
        long sum1 = 0L, sum = 0L;
        for(int i=0; i<queue1.length; i++){
            sum1 += queue1[i];
            sum += queue2[i];
        }
        sum+=sum1;
        if(sum%2==1)
            return -1;
        sum/=2;
        
        int[] arr = new int[2*queue1.length];
        for(int i=0; i<arr.length; i++)
            arr[i] = i<queue1.length ? queue1[i] : queue2[i-queue1.length];

        for(int s=0, e=queue1.length, count=0; s<arr.length && e<3*queue1.length;){
            if(sum1==sum) 
                return count;
            if(sum1>sum)
                sum1-=arr[s++];
            else
                sum1+=arr[e++%arr.length];
            count++;
        }
        
        return -1;
    }
}