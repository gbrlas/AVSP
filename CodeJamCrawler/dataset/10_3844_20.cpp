/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.*;
import java.util.*;
/**
 *
 * @author harry
 */

public class Main{

    public static boolean Flip(boolean val) {
      return val?false:true;
  }

    public static void main(String args[]) throws Exception {
        boolean ans=false;
        int j=0,k=0,l=0;
        BufferedReader in   = new BufferedReader(new FileReader("A-small-attempt1.in"));
        int T=Integer.parseInt(in.readLine());
        BufferedWriter out = new BufferedWriter(new FileWriter("filename2", true));
        for (int i=0;i<T;i++){
            String line=in.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            boolean Narray[]=new boolean[N];
            while (j<N){
                Narray[j]=false;
                j++;
            }
            for (k=1;k<=K;k++){
                Narray[0]=Flip(Narray[0]);
                for (l=1;l<N;l++){
                        if(!Narray[l] ){
                            if(Narray[0]){
                                break;
                            }
                            Narray[l]=Flip(Narray[l]);
                            l=1;
                            break;
                        }
                        if(!Narray[l-1] && !Narray[0])
                            Narray[l]=Flip(Narray[l]);
                }
            }
            k=0;
            while(k<(N-1) && Narray[k]){k++;}
            if(k==(N-1) && Narray[N-1])
                out.write("Case #"+(i+1)+": ON\n");
            else
                out.write("Case #"+(i+1)+": OFF\n");
        }
        out.close();
    }
}
