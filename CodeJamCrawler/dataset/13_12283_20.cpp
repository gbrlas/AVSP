

import java.io.*;
import java.util.Arrays;


public class Tic {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String x[] = {"XXXO","..O.",".O..","T..."};
BufferedReader h = new BufferedReader(new FileReader("A-small-attempt8.in"));
BufferedWriter bw = new BufferedWriter(new FileWriter("ride.out.txt"));

int c = Integer.parseInt(h.readLine());
int cc=1;
here:
    for (int o = cc; o <= c; o++) {
        cc++;
        for (int i = 0; i < 4; i++) {
         x[i]=h.readLine();   
        }
        h.readLine();
        String y[] = {"","","","","",""};
        String sol[]= new String[10];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                y[i]+=x[j].charAt(i);
                if(i==j){
                    y[4]+= x[i].charAt(j);
                    y[5] += x[i].charAt(3-j);
                }
            }
        }
//      System.out.println(Arrays.toString(x));
//       System.out.println(Arrays.toString(y));
        for (int i = 0; i < 4; i++) {
          sol[i]=new Tic().outPut(x[i]);  
          sol[i+4]=new Tic().outPut(y[i]);  
        }
        sol[8]=new Tic().outPut(y[4]);  
        sol[9]=new Tic().outPut(y[5]);  
    //    System.out.println(Arrays.toString(sol));
        for (int i = 0; i < sol.length; i++) {
            if(sol[i] == "X won"){
               // System.out.println("Case #"+o+": X won");
                bw.write("Case #"+o+": X won");
                bw.newLine();
               continue here;
            }
        }
        for (int i = 0; i < sol.length; i++) {
             if(sol[i] == "O won"){
             //   System.out.println("Case #"+o+": O won");
                 bw.write("Case #"+o+": O won");
                 bw.newLine();
                continue here;
            }
        }
        for (int i = 0; i < sol.length; i++) {
             if(sol[i] == "Game has not completed"){
          //      System.out.println("Case #"+o+": Game has not completed");
                 bw.write("Case #"+o+": Game has not completed");
                 bw.newLine();
                 continue here;
            }
        }
        for (int i = 0; i < sol.length; i++) {
            
             if(sol[i] == "Draw"){
             //   System.out.println("Case #"+o+": Draw");
                 bw.write("Case #"+o+": Draw");
                 bw.newLine();
                 continue here;
            }
        }
        
        bw.newLine();
       
      
    }
     
        bw.flush();
        bw.close();
    }
      boolean f =false;
    public String outPut(String a){
         f = false;
        int n = 0;
        for (int i = 0; i < 3; i++) {
        if(a.charAt(i) == a.charAt(i+1)){
            
            if(a.charAt(i) != '.' || a.charAt(i+1) != '.')
             n++; 
        }
        if(!f)
                if(a.charAt(i) == 'T' || a.charAt(i+1) == 'T' ){
                    n++;
                    f = true;
                }
        }
       // System.out.println(n);
        if(n == 3){
            if(a.contains("X"))
                return "X won"; 
            else if(a.contains("O"))
                return "O won"; 
         //   System.out.println(n);
        }else{
            if(a.contains("."))
                return "Game has not completed";
            else
                return "Draw";
        }
       return "" ;
    }
    
}
