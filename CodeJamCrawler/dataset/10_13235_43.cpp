/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
import java.io.*;
import java.util.*;
import java.math.*;
public class Google {
    public static String convierteBinario(BigInteger a){
        BigInteger num=a;
        BigInteger dos=new BigInteger("2");
        BigInteger cero=new BigInteger("0");
        String res="";
        while(!num.equals(cero)){
            res+=num.mod(dos).toString();
            num=num.divide(dos);
        }
        return res;
    }
    public static void main(String[] args) throws Exception{
        Scanner info =new Scanner(new FileReader("A-large.in"));
        PrintWriter archivoSalida=new PrintWriter(new FileWriter("salida.txt"), true);
        String linea;
        String numG="";
        String ar[];
        linea=info.nextLine();
        int num=Integer.parseInt(linea);
        boolean bandera1=true;
        for (int i = 0; i < num; i++) {
            bandera1=true;
            linea=info.nextLine();
            ar=linea.split(" ");
            int n=Integer.parseInt(ar[0]);
            int k=Integer.parseInt(ar[1]);
            BigInteger numBin=new BigInteger("0");
            BigInteger KA=new BigInteger(""+k);
            numBin.add(KA);

            String t= convierteBinario(KA);
            int longitud=t.length();
            if(longitud>=n)
                t=t.substring(0, n);
            else
                bandera1=false;
            for (int j = 0; j < t.length(); j++) {
                if(t.charAt(j)=='0'){
                    bandera1=false;
                    break;
                }
            }
            if(bandera1)
                archivoSalida.println("Case #"+ (i+1)+": ON");
            else
                archivoSalida.println("Case #"+ (i+1)+": OFF");
        }
    }
}