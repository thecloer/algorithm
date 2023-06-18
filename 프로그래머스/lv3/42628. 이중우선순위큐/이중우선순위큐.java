class Solution {
    public int[] solution(String[] operations) {
        SortedQueue q = new SortedQueue();
        for(String operation:operations){
            String[] temp = operation.split(" ");
            if(temp[0].equals("I"))
                q.add(Integer.parseInt(temp[1]));
            else if(temp[0].equals("D") && !q.isEmpty()){
                if(temp[1].equals("-1"))
                    q.popLeft();
                else if(temp[1].equals("1"))
                    q.popRight();
            }
        }
        
        int[] answer = new int[2];
        if(!q.isEmpty()){
            answer[0] = q.peekRight();
            answer[1] = q.peekLeft();
        }
        return answer;
    }
}

class SortedQueue{
    private class Node{
        int value;
        Node prev;
        Node next;
        Node(int value, Node prev, Node next){
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }
    private Node head = null;
    private Node tail = null;
    boolean isEmpty(){
        return head==null;
    }
    void add(int v){
        if(isEmpty()){
            Node newNode = new Node(v, null, null); 
            head = newNode;
            tail = newNode;
        } else {
            Node node = head;
            while(node.next!=null){
                if(node.value<=v && node.next.value>v)
                    break;
                node = node.next;
            }
            if(node.value>v){
                Node newNode = new Node(v, null, node); 
                head = newNode;
            } else {
                Node newNode = new Node(v, node, node.next); 
                node.next = newNode;
                if(newNode.next==null) 
                    tail = newNode;
                else
                    newNode.next.prev = newNode;
            }
        }
    }
    int popLeft(){
        Node node = head;
        head = node.next;
        if(head == null)
            tail = null;
        else
            head.prev = null;
        return node.value;
    }
    int popRight(){
        Node node = tail;
        tail = node.prev;
        if(tail == null)
            head = null;
        else
            tail.next = null;
        return node.value;
    }
    int peekLeft(){
        return head.value;
    }
    int peekRight(){
        return tail.value;
    }
}
