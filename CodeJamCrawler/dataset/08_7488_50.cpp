
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
import java.util.HashMap;
import java.util.Hashtable;

/**
 *
 * @author Icarus
 * 
 * 
 */
public class CodeJam_Qualification_Round_First {

    
    public static String process(Hashtable engines, String[] query) {
        int min = 0;
        for (int i = 0; i < query.length; i++) {
            engines.put(query[i], ((Integer) engines.get(query[i])) + 1);
            Enumeration keys = engines.keys(); 
            boolean was_all = true;
            while (keys.hasMoreElements()) {
                int temp = ((Integer) engines.get(keys.nextElement())).intValue(); 
                if (temp == 0) was_all = false;
            }
            if (was_all) {
                keys = engines.keys();
                while (keys.hasMoreElements()) {
                    engines.put(keys.nextElement(), new Integer(0));
                }
                engines.put(query[i], ((Integer) engines.get(query[i])) + 1);
                min++;
            }
        }
        return "" + min;
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
                int number_of_engines = Integer.parseInt(sor);
                Hashtable engines = new Hashtable();
                for (int j = 0; j < number_of_engines; j++) {
                    sor = br.readLine(); 
                    engines.put(sor, new Integer(0));
                }                
                sor = br.readLine(); 
                int query_length = Integer.parseInt(sor);
                String[] query = new String[query_length];
                for (int j = 0; j < query_length; j++) {
                    sor = br.readLine(); 
                    query[j] = sor;                    
                }
                
                String output = "";
                output = process(engines, query); 
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
