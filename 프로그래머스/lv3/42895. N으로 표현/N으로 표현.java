import java.util.*;
class Solution {
    public int solution(int N, int number) {
        if(N==number) return 1;
        int answer = -1;
        Set<Integer>[] setArray = new HashSet[9];
        for(int i=1; i<=8; i++){
            setArray[i] = new HashSet();
            setArray[i].add(Integer.parseInt(Integer.toString(N).repeat(i)));
            if(i==1) continue;
            for(int j=1; j<=i/2; j++){
                for(Integer a: setArray[j]){
                    for(Integer b: setArray[i-j]){
                        setArray[i].add(a+b);
                        setArray[i].add(a-b);
                        setArray[i].add(b-a);
                        setArray[i].add(a*b);
                        if(a!=0) 
                            setArray[i].add(b/a);
                        if(b!=0) 
                            setArray[i].add(a/b);
                        if(setArray[i].contains(number))
                            return i;
                    }
                }
            }
        }
        return -1;
    }
}