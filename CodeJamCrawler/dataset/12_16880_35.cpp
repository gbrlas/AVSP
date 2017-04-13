

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Solution {
    static DataInputStream in = new DataInputStream(new BufferedInputStream(System.in));
    static BufferedReader din = new BufferedReader( new InputStreamReader(in));
    public static void main(String args[]){
        HashMap hm = new HashMap(27);
        hm.put('a','y');
        hm.put('b','h');
        hm.put('c','e');
        hm.put('d','s');
        hm.put('e','o');
        hm.put('f','c');
        hm.put('g','v');
        hm.put('h','x');
        hm.put('i','d');
        hm.put('j','u');
        hm.put('k','i');
        hm.put('l','g');
        hm.put('m','l');
        hm.put('n','b');
        hm.put('o','k');
        hm.put('p','r');
        hm.put('q','z');
        hm.put('r','t');
        hm.put('s','n');
        hm.put('t','w');
        hm.put('u','j');
        hm.put('v','p');
        hm.put('w','f');
        hm.put('x','m');
        hm.put('y','a');
        hm.put('z','q');
        hm.put(' ',' ');

        int n = parseInt(getLine());
        String[] g = new String[n];
        String out="Case #";
        for(int i = 0;i<n;i++){
            g[i] = getLine();
        }
        int len;
        for(int i = 0;i<n;i++){
            out=out + (i+1)+": ";
            len = g[i].length();
            for(int j =0;j<len;j++){
                out=out+hm.get(g[i].charAt(j));
            }
            soutln(out);
            out="Case #";
        }

    }

    public static String getLine(){
        String input = "";
        try {
            input = din.readLine();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return input;
    }

    public static int parseInt(String s){
        return Integer.parseInt(s);
    }

    public static void sout(Object n){
        System.out.print(n);
    }
    public static void soutln(Object n){
        System.out.println(n);
    }
}

