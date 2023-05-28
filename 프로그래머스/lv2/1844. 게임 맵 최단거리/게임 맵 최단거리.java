import java.util.*;
class Solution {
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        Queue<Position> queue = new LinkedList();
        queue.add(new Position(0,0,0));
        maps[0][0] = 0;
        while(!queue.isEmpty()){
            Position current = queue.poll();
            Position[] nexts = current.getNextPositions(n,m);
            for(Position next:nexts){
                int x = next.getX();
                int y = next.getY();
                if(maps[x][y] == 1){
                    if(next.isHere(n-1,m-1))
                        return next.getDistance();
                    maps[x][y] = 0;
                    queue.add(next);
                }
            }
        }
        return -1;
    }
}

class Position {
    private int x, y, distance;
    Position(int x, int y, int prevDistance){
        this.x = x;
        this.y = y;
        this.distance = prevDistance + 1;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getDistance(){
        return distance;
    }
    Position[] getNextPositions(int n, int m){
        ArrayList<Position> list = new ArrayList();
        for(int i=0; i<4; i++){
            int nextX = x + (i/2==0? 0 : i%2==0? -1: 1);
            int nextY = y + (i/2==1? 0 : i%2==0? -1: 1);
            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m)
                list.add(new Position(nextX, nextY, distance));
        }
        return list.toArray(new Position[list.size()]);
    }
    boolean isHere(int desX, int desY){
        return x == desX && y == desY;
    }
}