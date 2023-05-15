class Solution {
    public String solution(String new_id) {
        return new ID(new_id)
                .toLowerCase()
                .sanitize()
                .removeDotSequence()
                .removeEndPointsDot()
                .limitLength(3,15)
                .getString();
    }
}

class ID{
    private String s;
    
    ID(String s){
        this.s = s;
    }
    ID toLowerCase(){
        s = s.toLowerCase();
        return this;
    }
    ID sanitize(){
        s = s.replaceAll("[^a-z0-9._-]","");
        return this;
    }
    ID removeDotSequence(){
        s = s.replaceAll("\\.{2,}",".");
        return this;
    }
    ID removeEndPointsDot(){
        s = s.replaceAll("^\\.|\\.$","");
        return this;
    }
    ID limitLength(int min, int max){
        if(s.isEmpty()) whenLengthEmpty();
        if(s.length() < min) whenLengthShorterThan(min);
        else if(s.length() > max) {
            whenLengthLongerThan(max);
            removeEndPointsDot();
        }
        return this;
    }
    private void whenLengthEmpty(){
        s = "a";
    }
    private void whenLengthShorterThan(int min){
        while(s.length() < min)
            s += s.charAt(s.length()-1);
    }
    private void whenLengthLongerThan(int max){
        s = s.substring(0,max);
    }
    String getString(){
        return s;
    }
}