
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;


/** @author Philip Rud */
public class TrainTimetable {
    
    public static class Solution {
        public int a;
        public int b;
        
        public Solution(int a, int b) {
            this.a = a; this.b = b;
        }
    }

    public static Solution solve(int taTime, ArrayList<Integer> aArrival, ArrayList<Integer> aDeparture, ArrayList<Integer> bArrival, ArrayList<Integer> bDeparture) {
        int a = 0;
        int b = 0;
        
        for (int departure: aDeparture) {
            boolean hasExisting = false;
            
            for (int i = 0; i < aArrival.size(); i++)
                if (aArrival.get(i) + taTime <= departure) {
                    aArrival.remove(i);
                    hasExisting = true;
                    break;
                }
            if (!hasExisting) a++;
        }
        
        for (int departure: bDeparture) {
            boolean hasExisting = false;
            
            for (int i = 0; i < bArrival.size(); i++)
                if (bArrival.get(i) + taTime <= departure) {
                    bArrival.remove(i);
                    hasExisting = true;
                    break;
                }
            if (!hasExisting) b++;
        }
        
        return new Solution(a, b);
    }
    
    public static void main(String[] args) {
        Scanner fin = null;
        FileWriter fout = null;
        
        try {
            fin = new Scanner(new File("B-large.in"));
            fout = new FileWriter("B-large.out");
            
            int testNumber = fin.nextInt();
            for (int i = 1; i <= testNumber; i++) {
                
                int t = fin.nextInt();
                int na = fin.nextInt(); int nb = fin.nextInt();
                
                ArrayList<Integer> aArrival = new ArrayList<Integer>();
                ArrayList<Integer> aDeparture = new ArrayList<Integer>();
                ArrayList<Integer> bArrival = new ArrayList<Integer>();
                ArrayList<Integer> bDeparture = new ArrayList<Integer>();
                
                String[] entry;
                
                for (int j = 0; j < na; j++) {
                    entry = fin.next().split(":");
                    aDeparture.add(Integer.parseInt(entry[0]) * 60 + Integer.parseInt(entry[1]));
                    entry = fin.next().split(":");
                    bArrival.add(Integer.parseInt(entry[0]) * 60 + Integer.parseInt(entry[1]));
                }
                
                for (int j = 0; j < nb; j++) {
                    entry = fin.next().split(":");
                    bDeparture.add(Integer.parseInt(entry[0]) * 60 + Integer.parseInt(entry[1]));
                    entry = fin.next().split(":");
                    aArrival.add(Integer.parseInt(entry[0]) * 60 + Integer.parseInt(entry[1]));
                }
                
                Collections.sort(aArrival);
                Collections.sort(aDeparture);
                Collections.sort(bArrival);
                Collections.sort(bDeparture);
                
                Solution solution = solve(t, aArrival, aDeparture, bArrival, bDeparture);
                
                fout.write(String.format(Locale.US, "Case #%d: %d %d\n", i, solution.a, solution.b));
            }
        } catch (IOException e) {
            System.out.println(e.getStackTrace());
        }

        try {fin.close();} catch (Exception e) {}
        try {fout.close();} catch (Exception e) {}        
    }

}
