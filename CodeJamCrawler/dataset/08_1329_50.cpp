import java.util.*;
import java.io.*;

/**
 * Created by IntelliJ IDEA.
 * User: sedtawut
 * Date: 17 ¡.¤. 2551
 * Time: 12:15:11
 * To change this template use File | Settings | File Templates.
 */
public class TrainTimetable {
    private int turnAround;
    private Pool aPool;
    private Pool bPool;
    private List<Trip> trips;

    public static final int A_B = 0;
    public static final int B_A = 1;

    public TrainTimetable(int turnAround) {
        this.turnAround = turnAround;
        this.aPool = new Pool();
        this.bPool = new Pool();
        this.trips = new ArrayList<Trip>();
    }

    public void addTrips(String time, int dir) {
        String[] times = time.split(" ");
        Trip trip = new Trip(times[0], times[1], dir);
        trips.add(trip);
    }

    public String  process() {
        Collections.sort(trips);
        for (int i = 0; i < trips.size(); i++) {
            Trip trip = trips.get(i);
            if (trip.dir == A_B) {
                System.out.print("-> AB:" + trip.start +" " + trip.end);
                aPool.get(trip.start);
                int newReadyTime = trip.end + turnAround;
                bPool.returnPool(newReadyTime);
            } else {
                System.out.print("-> BA:" + trip.start +" " + trip.end);
                bPool.get(trip.start);
                int newReadyTime = trip.end + turnAround;
                aPool.returnPool(newReadyTime);
            }
        }

        return aPool.count + " " + bPool.count; 
    }

    private class Trip implements Comparable<Trip> {
        int start;
        int end;
        int dir;

        private Trip(String start, String end, int dir) {
            this.start = getTime(start);
            this.end = getTime(end);
            this.dir = dir;
        }

        private int getTime(String time) {
            String[] s = time.split(":");
            return Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]);
        }

        public int compareTo(Trip another) {
            int thisVal = this.start;
            int anotherVal = another.start;
            return (thisVal < anotherVal ? -1 : (thisVal == anotherVal ? 0 : 1));
        }
    }

    private class Pool {
        int count;
        List<Integer> list = new ArrayList<Integer>();

        public void get(Integer startTime) {
            Collections.sort(list);
            System.out.print(" " + list + "");
            for (int i = 0; i < list.size(); i++) {
                Integer myTime = list.get(i);
                if (myTime <= startTime) {
                    list.remove(i);
                    System.out.print(" get:" +myTime + " need:" + startTime + " c:" + count);
                    return;
                }
            }

            count++;
            System.out.print("get NO count " + count);
        }

        public void returnPool(Integer time) {
            System.out.println(" ret:" + time);
            list.add(time);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("B-small-attempt3.in"));
//        BufferedReader in = new BufferedReader(new FileReader("a.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("B-small-attempt3.out"));
//        PrintWriter out = new PrintWriter(new FileWriter("a.txt.out"));
        int nCase = Integer.parseInt(in.readLine());
        for (int i = 0; i < nCase; i++) {
            System.out.println("------"+ i);
            int turnTime = Integer.parseInt(in.readLine());
            String[] nTrain = in.readLine().split(" ");
            int nA = Integer.parseInt(nTrain[0]);
            int nB = Integer.parseInt(nTrain[1]);

            TrainTimetable trainTimetable = new TrainTimetable(turnTime);
            for (int j = 0; j < nA; j++) {
                trainTimetable.addTrips(in.readLine(), A_B);
            }
            for (int j = 0; j < nB; j++) {
                trainTimetable.addTrips(in.readLine(), B_A);
            }            

            out.println("Case #"+(i+1)+": " + trainTimetable.process());
        }

        in.close();
        out.close();
    }
}
