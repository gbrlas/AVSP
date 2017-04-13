import java.util.*;
import java.io.*;

/**
 * <p>Google code jam 2008. Train timetable</p>
 *
 * @author Nikolay Ugarov, xko@xko.kiev.ua
ca */
public class GCJ2008TrainTimetable {
    static class Station {

        List departures = new ArrayList();
        List arrivals =  new ArrayList();

        void addArrival(String st, int turnover) {
            int h = Integer.parseInt(st.split(":")[0]);
            int m = Integer.parseInt(st.split(":")[1]);
            arrivals.add(new Integer(h*60+m+turnover));
//            GregorianCalendar cal = new GregorianCalendar(0, 0, 0, h, m);
//            cal.add(Calendar.MINUTE,turnover);
//            addArrival(cal);
        }

        void addDeparture(String st) {
            int h = Integer.parseInt(st.split(":")[0]);
            int m = Integer.parseInt(st.split(":")[1]);
            departures.add(new Integer(h*60+m));

//            addDeparture(new GregorianCalendar(0,0,0,h,m));
        }

//        void addArrival(Calendar ar) {
//            arrivals.add(ar);
//        }
//
//        void addDeparture(Calendar dep) {
//            departures.add(dep);
//        }

        int trainsAtStart() {
            int res = 0;
            Collections.sort(arrivals, Collections.reverseOrder());

            for (Iterator i = departures.iterator(); i.hasNext();) {
                Comparable dep = (Comparable) i.next();
                boolean hasTrain = false;
                for (Iterator j = arrivals.iterator(); j.hasNext() && !hasTrain;) {
                    Comparable arr = (Comparable) j.next();
                    if (arr.compareTo(dep) <= 0) {
                        j.remove();
                        hasTrain = true;
                    }
                }
                if (!hasTrain) res++;
            }
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(args[0]));

        PrintStream out = new PrintStream(new FileOutputStream(args[1]));
        long n = Integer.parseInt(in.readLine());
        for (int i = 1; i <= n; i++) {
            System.out.println("Case:" + i);
            int turnover = Integer.parseInt(in.readLine());
            String[] trips = in.readLine().split(" ");
            int tripsAB = Integer.parseInt(trips[0]);
            int tripsBA = Integer.parseInt(trips[1]);
            Station A = new Station();
            Station B = new Station();
            for (int j = 1; j <= tripsAB; j++) {
                String[] trip = in.readLine().split(" ");
                A.addDeparture(trip[0]);
                B.addArrival(trip[1],turnover);
            }
            for (int j = 1; j <= tripsBA; j++) {
                String[] trip = in.readLine().split(" ");
                B.addDeparture(trip[0]);
                A.addArrival(trip[1],turnover);
            }
            out.println("Case #" + i + ": "+ A.trainsAtStart()+" "+B.trainsAtStart());
        }
    }
}
