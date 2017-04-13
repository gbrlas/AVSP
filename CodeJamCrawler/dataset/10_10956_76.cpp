/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;
import java.io.*;

/**
 *
 * @author 51isoft
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Scanner cin=new Scanner(new File("L:\\learning\\gcj2010\\B-small.in"));
        PrintWriter cout=new PrintWriter("L:\\learning\\gcj2010\\B-small.out");
        int kase,n;
        BigInteger[] val=new BigInteger[1001];
        BigInteger t,y;
        kase=cin.nextInt();
        for (int i=0;i<kase;i++) {
            n=cin.nextInt();
            for (int j=0;j<n;j++) val[j]=cin.nextBigInteger();
            t=val[0].subtract(val[1]).abs();
            for (int j=0;j<n;j++) {
                for (int k=j+1;k<n;k++) {
                    t=t.gcd(val[j].subtract(val[k]).abs());
                }
            }
            y=val[0].mod(t);
            y=t.subtract(y).mod(t);
            cout.printf("Case #%d: ",i+1);
            cout.println(y);
        }
        cout.close();
    }

}
