package com.atulvani;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.List;

public class Bullseye {
    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("Bullseye.in"));

        int totalCases = Integer.parseInt(reader.readLine());
        List<String> kase;
        BigInteger initialRadius = BigInteger.ZERO;
        BigInteger paintQuantity = BigInteger.ZERO;
        BigInteger numberOfRings = BigInteger.ZERO;
        for(int i=0; i<totalCases; i++) {
            kase = Arrays.asList(reader.readLine().split(" "));
            initialRadius = new BigInteger(kase.get(0));
            paintQuantity = new BigInteger(kase.get(1));
            //the first ring
            paintQuantity = paintQuantity.subtract((initialRadius.multiply(BigInteger.valueOf(2))).add(BigInteger.ONE));
            initialRadius = initialRadius.add(BigInteger.valueOf(2));
            numberOfRings = BigInteger.ONE;
             //the first ring
            while(paintQuantity.compareTo(BigInteger.ZERO) == 1) {
                paintQuantity = paintQuantity.subtract((initialRadius.multiply(BigInteger.valueOf(2))).add(BigInteger.ONE));
                initialRadius = initialRadius.add(BigInteger.valueOf(2));
                if(paintQuantity.compareTo(BigInteger.ZERO) < 0) {
                    break;
                }
                numberOfRings = numberOfRings.add(BigInteger.ONE);
            }
            StringBuffer buffer = new StringBuffer();
            buffer.append("Case #");
            buffer.append(String.valueOf(i+1)).append(": ");
            buffer.append(numberOfRings);
            System.out.println(buffer.toString());
            buffer.setLength(0);
       }
        reader.close();
    }
}