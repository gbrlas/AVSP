
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;

/**
 *
 * @author Icarus
 * 
 * 
 */
public class CodeJam_Qualification_Round_Second {
    
    public static int A_train; 
    public static int B_train;
    public static int turnround;

    public static class Trip {
        public int start_hour;
        public int start_minute;
        public int arive_hour;
        public int arive_min;
        public boolean counted = false; 
        public Trip() {
            
        }
    }
    
    public static String process(Trip[] trips_a, Trip[] trips_b) {

        voyage(trips_a, trips_b);
        return A_train + " " + B_train;
    }
    
    public static void voyage(Trip[] trips_a, Trip[] trips_b) {
        A_train = 0; 
        B_train = 0;
        while (!all_train_counted(trips_a, trips_b)) {                   
            int a_first = getfirst_not_counted_trip_index(trips_a);    
            int b_first = getfirst_not_counted_trip_index(trips_b);    
            if ((a_first != -1) && (b_first != -1)) {
                if (( trips_a[a_first].start_hour * 60 + trips_a[a_first].start_minute) < ( trips_b[b_first].start_hour * 60 + trips_b[b_first].start_minute)) {
                    A_train++;
                    voyage2(trips_a, trips_b, true);
                } else {
                    B_train++;
                    voyage2(trips_a, trips_b, false);
                }             
            } else if (a_first == -1 && b_first != -1) {
                B_train++;
                voyage2(trips_a, trips_b, false);
            } else if (b_first == -1 && a_first != -1) {
                A_train++;
                voyage2(trips_a, trips_b, true);
            }
        }                
    }
    
    public static void voyage2(Trip[] trips_a, Trip[] trips_b, boolean start_a) {
        if (start_a) {
            int a_start = getfirst_not_counted_trip_index(trips_a);
            if (a_start == -1 ) return;
            trips_a[a_start].counted = true; 
            int min = trips_a[a_start].arive_hour * 60 + trips_a[a_start].arive_min + turnround; 
            voyage3(trips_a, trips_b, false, min); 
        } else {
            int b_start = getfirst_not_counted_trip_index(trips_b);
            if (b_start == -1 ) return;
            trips_b[b_start].counted = true; 
            int min = trips_b[b_start].arive_hour * 60 + trips_b[b_start].arive_min + turnround;  
            voyage3(trips_a, trips_b, true, min); 
        }           
    }
    
    public static void voyage3(Trip[] trips_a, Trip[] trips_b, boolean start_a, int __min) {
        if (start_a) {
            int a_start = getfirst_not_counted_trip_index(trips_a, __min);
            if (a_start == -1 ) return;
            trips_a[a_start].counted = true; 
            int min = trips_a[a_start].arive_hour * 60 + trips_a[a_start].arive_min + turnround; 
            voyage3(trips_a, trips_b, false, min); 
        } else {
            int b_start = getfirst_not_counted_trip_index(trips_b, __min);
            if (b_start == -1 ) return;
            trips_b[b_start].counted = true; 
            int min = trips_b[b_start].arive_hour * 60 + trips_b[b_start].arive_min + turnround; 
            voyage3(trips_a, trips_b, true, min); 
        }           
    }
    
    public static int getfirst_not_counted_trip_index(Trip[] trip, int __min) {
        int min = 2400; 
        int min_index = -1; 
        for (int i = 0; i < trip.length; i++) {
            int temp = (trip[i].start_hour * 60 + trip[i].start_minute);
            if ((temp < min) && (__min <= temp) && (!trip[i].counted)) {
                min = (trip[i].start_hour * 60 + trip[i].start_minute); 
                min_index = i;
            } 
        }
        return min_index;
    }
    
    public static int getfirst_not_counted_trip_index(Trip[] trip) {
        int min = 2400; 
        int min_index = -1; 
        for (int i = 0; i < trip.length; i++) {
            if (((trip[i].start_hour * 60 + trip[i].start_minute) < min) && (!trip[i].counted)) {
                min = (trip[i].start_hour * 60 + trip[i].start_minute); 
                min_index = i;
            } 
        }
        return min_index;
    }
    
    public static boolean all_train_counted(Trip[] trips_a, Trip[] trips_b) {
        for (int i = 0; i < trips_a.length; i++)
            if (trips_a[i].counted == false) return false;
        for (int i = 0; i < trips_b.length; i++)
            if (trips_b[i].counted == false) return false;
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        
        File input_file = new File(args[0]);
        String sor = ""; 
        int number_of_casses = 0; 
        
        File output_file = new File(args[1]);
        
        // try {
            FileReader fr = new FileReader(input_file);
            BufferedReader br = new BufferedReader(fr);
            
            FileWriter fw = new FileWriter(output_file);
            BufferedWriter bw = new BufferedWriter(fw);
            
            sor = br.readLine(); 
            number_of_casses = Integer.parseInt(sor);
            for (int i = 0; i < number_of_casses; i++) {
                sor = br.readLine(); 
                turnround = Integer.parseInt(sor);  
                sor = br.readLine(); 
                int a_to_b = Integer.parseInt(sor.split(" ")[0]);
                int b_to_a = Integer.parseInt(sor.split(" ")[1]);
                Trip[] trips_a = new Trip[a_to_b];
                Trip[] trips_b = new Trip[b_to_a];
                for (int j = 0; j < a_to_b; j++) {
                    sor = br.readLine();
                    Trip t = new Trip();
                    t.start_hour = Integer.parseInt(sor.split(" ")[0].split(":")[0]);
                    t.start_minute = Integer.parseInt(sor.split(" ")[0].split(":")[1]);
                    t.arive_hour = Integer.parseInt(sor.split(" ")[1].split(":")[0]);
                    t.arive_min = Integer.parseInt(sor.split(" ")[1].split(":")[1]);
                    trips_a[j] = t;
                }
                for (int j = 0; j < b_to_a; j++) {
                    sor = br.readLine();
                    Trip t = new Trip();
                    t.start_hour = Integer.parseInt(sor.split(" ")[0].split(":")[0]);
                    t.start_minute = Integer.parseInt(sor.split(" ")[0].split(":")[1]);
                    t.arive_hour = Integer.parseInt(sor.split(" ")[1].split(":")[0]);
                    t.arive_min = Integer.parseInt(sor.split(" ")[1].split(":")[1]);
                    trips_b[j] = t;
                }                
                String output = "";
                output = process(trips_a, trips_b);
                System.out.println("Case #" + (i+1) + ": " + output);
                bw.write("Case #" + (i+1) + ": " + output);
                bw.newLine();
            }
            bw.close();
            fw.close();
         // } 
         // catch (IOException e) {
         //   System.out.println(e.toString());
         //}
    }
}
