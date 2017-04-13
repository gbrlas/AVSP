/**
 * CookieClickerAlpha.java
 * 
 * @version 1.0
 * @since 2014-04-11
 * @author Chad Fawcett
 */

import java.util.Scanner;
import java.io.File;
import java.text.DecimalFormat;

public class CookieClickerAlpha {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("B-large.in.txt"));
            
            int caseCount = scan.nextInt();
            
            for (int i = 0; i < caseCount; i++) {
                double c = scan.nextDouble();
                double f = scan.nextDouble();
                double x = scan.nextDouble();
                
                DecimalFormat df = new DecimalFormat("#.0000000");
                System.out.println("Case #" + (i + 1) + ": " + df.format(calculateSeconds(c, f, x)));
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        
        
        
        //System.out.println(calculateSeconds(c, f, x));
        //System.out.println(calculateSeconds(30.50000, 3.14159, 1999.19990, 2.0));
        //System.out.println(calculateSeconds(500.0, 4.0, 2000.0, 2.0));
    }
    
    public static double calculateSeconds(double c, double f, double x) {
        double r = 2.0;
        double base = 0.0;
        double current;
        double next;
        
        do {
            current = base + x / r;
            base += c / r;
            r += f;
            next = base + x / r;
        } while (current > next);
        
        return current;
    }
}