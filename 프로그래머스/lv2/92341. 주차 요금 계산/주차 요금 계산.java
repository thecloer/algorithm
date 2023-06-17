import java.util.*;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        ParkingLot parkingLot = new ParkingLot(fees[0],fees[1],fees[2],fees[3]);
        for(String record:records){
            String[] arr = record.split(" ");
            if(arr[2].equals("IN")) 
                parkingLot.in(arr[1], arr[0]);
            else if(arr[2].equals("OUT")) 
                parkingLot.out(arr[1], arr[0]);
        }
        parkingLot.close();
        
        return parkingLot.getBills();
    }
}
class ParkingLot{
    private final String LIMIT_TIME = "23:59";
    private final int DEFAULT_TIME;
    private final int DEFAULT_FEE;
    private final int UNIT_TIME;
    private final int UNIT_FEE;
    private Map<String,String> parkedCars = new HashMap();
    private Map<String,Integer> times = new HashMap();
    ParkingLot(int defaultTime, int defaultFee, int unitTime, int unitFee){
        this.DEFAULT_TIME = defaultTime;
        this.DEFAULT_FEE = defaultFee;
        this.UNIT_TIME = unitTime;
        this.UNIT_FEE = unitFee;
    }
    void in(String car, String inTime){
        parkedCars.put(car,inTime);
    }
    void out(String car, String outTime){
        times.put(car, times.getOrDefault(car, 0) + getTimeDiff(parkedCars.get(car), outTime));
        parkedCars.put(car, LIMIT_TIME);
    }
    void close(){
        Iterator<String> parkedCarsIter = parkedCars.keySet().iterator();
        while(parkedCarsIter.hasNext())
            out(parkedCarsIter.next(), LIMIT_TIME);
    }
    int[] getBills() {
        List<String> carList = new ArrayList(times.keySet());
        carList.sort((a,b)->a.compareTo(b));
        int[] bills = new int[carList.size()];
        for(int i=0; i<bills.length; i++)
            bills[i] = calculateFee(times.get(carList.get(i)));
        return bills;
    }
    
    private int calculateFee(int time) {
        if(time <= DEFAULT_TIME) return DEFAULT_FEE;
        return DEFAULT_FEE
            + UNIT_FEE * (int)Math.ceil((double)(time - DEFAULT_TIME)/UNIT_TIME);
    }
    private int getTimeDiff(String start, String end){
        return 60 * (Integer.parseInt(end.substring(0,2)) 
                - Integer.parseInt(start.substring(0,2))) 
                + Integer.parseInt(end.substring(3,5)) 
                - Integer.parseInt(start.substring(3,5));
    }
}