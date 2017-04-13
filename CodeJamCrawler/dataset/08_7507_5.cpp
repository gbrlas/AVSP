/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Icarus
 */
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
/**
 *
 * @author Icarus
 * 
 * 
 */
public class First_problem {

    
    public static String process(int max_betuk_egy_gombon, int gombok_szama, int abc_hossza, int[] abc_gyak) {
        int[] abc_temp = new int[abc_gyak.length]; 
        int[] abc_gomb = new int[abc_gyak.length];
        for (int i = 0; i < abc_gyak.length; i++) {
            abc_temp[i] = abc_gyak[i];
            // System.out.println(" " + abc_temp[i]);
        }
        for (int i = 0; i < abc_temp.length; i++) 
            for (int j = i+1; j < abc_temp.length; j++) 
                if (abc_temp[i] < abc_temp[j]) {
                    int temp = abc_temp[j]; 
                    abc_temp[j] = abc_temp[i];
                    abc_temp[i] = temp;
                }
        // System.out.println();
        for (int i = 0; i < abc_temp.length; i++) {
           //  System.out.println(" " + abc_temp[i]);
        }
        int gomb = 1;
        int j = 1;            
        for (int i = 0; i < abc_temp.length; i++) {                        
            if (j > max_betuk_egy_gombon)
                return "Impossible";
            abc_gomb[i] = j; 
            gomb++;
            if (gomb > gombok_szama) {
                gomb = 1; 
                j++; 
                }
        }
        int gombnyomasok_szama = 0; 
        for (int i = 0; i < abc_temp.length; i++) {
            gombnyomasok_szama += abc_temp[i] * abc_gomb[i];
        }
        return "" + gombnyomasok_szama; 
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
                String[] parameterek = sor.split(" ");
                sor = br.readLine();
                String[] abc_gyak_temp = sor.split(" ");
                int[] abc_gyak = new int[Integer.parseInt(parameterek[2])];
                for (int j = 0; j < abc_gyak.length; j++) {
                    abc_gyak[j] = Integer.parseInt(abc_gyak_temp[j]); 
                }
                String output = "";
                output = process(Integer.parseInt(parameterek[0]), 
                                 Integer.parseInt(parameterek[1]), 
                                 Integer.parseInt(parameterek[2]), 
                                 abc_gyak);
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

