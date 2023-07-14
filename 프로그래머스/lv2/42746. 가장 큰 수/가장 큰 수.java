import java.util.*;
import java.util.stream.*;
class Solution {
    public String solution(int[] numbers) {
        int zeroCount = 0;
        for(int n:numbers)
            if(n==0)
                zeroCount++;
        return zeroCount == numbers.length 
            ? "0" 
            : Arrays.stream(numbers)
            .boxed()
            .map(i->i.toString())
            .sorted((a,b)->(b+a).compareTo(a+b))
            .collect(Collectors.joining());
    }
}