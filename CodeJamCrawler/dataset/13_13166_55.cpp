/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
/*import java.util.List;
import java.util.Arrays;
import java.util.Collections;*/
      
/**
 *
 * @author mohit
 */
public class A2013 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // TODO code application logic 
            BufferedReader reader = new BufferedReader(new FileReader("F:\\codejam\\C-small-attempt1.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("F:\\codejam\\outpt.out"));
            int T = Integer.parseInt(reader.readLine());
            for (int i = 1; i <= T; i++)
            {   
                System.out.println(i);
                String[] s = reader.readLine().split(" ");
                long A = Long.parseLong(s[0]);
                long B = Long.parseLong(s[1]);
                int result = 0;
                long SA = (long)(Math.ceil(Math.sqrt(A)));
                long SB = (long)(Math.floor(Math.sqrt(B)));
                for (long j = SA; j <= SB; j++)
                {
                    
                    //System.Console.WriteLine(j);
                    if (isPalindrom(j))
                    {
                        if (isPalindrom(j*j))
                        {
                            //System.out.println(j);
                            result++;
                        }
                    }
                }
                writer.write("Case #"+i+": " +result);
                writer.newLine();
            }

            reader.close();
            writer.close();
        } catch (Exception ex) {
            Logger.getLogger(A2013.class.getName()).log(Level.SEVERE, null, ex);
        }
            
    }
    
    private static boolean isPalindrom(long n)
    {       
           /* if ((n <= 4 && n >= 10) || (n <= 23 && n >= 100) || (n <= 2003 && n >= 10000) || (n <= 20103 && n >= 100000) || (n <= 2001003 && n >= 10000000))
            {
                return false;
            }*/
            String s = String.valueOf(n);
            String r = new StringBuilder(s).reverse().toString();

            return (s.equals(r));
               
    }

        
}
