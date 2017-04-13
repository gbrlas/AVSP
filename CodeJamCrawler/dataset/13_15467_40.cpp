package com.atulvani;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class FairAndSquareUtil {
    public static ArrayList<Integer> strToIntList(List<String> strList) {
        ArrayList<Integer> intList = new ArrayList<Integer>();
        for(int i=0; i<strList.size(); i++) {
            intList.add(Integer.parseInt(strList.get(i)));
        }
        return intList;
    }
    public static boolean isPalindrom(String str) {
        boolean isPalindrom = true;
        List<String> strList = Arrays.asList(str.split(""));
        for(int i=1; i<strList.size(); i++) {
            isPalindrom = isPalindrom && (strList.get(i).equals(strList.get(strList.size()-i)));
        }
        return isPalindrom;
    }
}

public class FairAndSquare {
    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("FairAndSquare.in"));

        int totalCases = Integer.parseInt(reader.readLine());
        // create case object for each case
        for(int i=0; i<totalCases; i++) {
            String minMax[] = reader.readLine().split(" ");
            long min = Integer.parseInt(minMax[0]);
            long max = Integer.parseInt(minMax[1]);
            int count = 0;

            StringBuffer buffer = new StringBuffer();
            buffer.append("Case #");
            buffer.append(String.valueOf(i+1)).append(": ");
            for(long j=min; j<=max; j++) {
                double k = Math.sqrt(j);
                if(Double.compare(k, Math.floor(k)) == 0) {
                    if(FairAndSquareUtil.isPalindrom(String.valueOf(j)) && FairAndSquareUtil.isPalindrom(String.valueOf((int) k))) {
                        count++;
                    }
                }
            }
            buffer.append(count);
            System.out.println(buffer.toString());
            buffer.setLength(0);
        }
        reader.close();
    }
}