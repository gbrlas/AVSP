
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author user
 */
public class palin {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        PrintWriter out = new PrintWriter(new FileWriter("final.txt"), true);
        String message="";
        Scanner br = new Scanner(System.in);
        String cases = br.nextLine();
        int num = Integer.parseInt(cases);
        for (int i = 1; i <= num; i++) {
                
                String input = br.nextLine();
                StringTokenizer st = new StringTokenizer(input);
                long fst= Integer.parseInt(st.nextToken());
                long sec= Integer.parseInt(st.nextToken());
                long ch;
                double sqr;
                boolean valid;
                String play;
                long count=0;
                for (long j = fst; j <= sec; j++) {
                
                sqr= Math.sqrt(j);
                ch = (long)sqr;
                    //System.out.println(sqr);
                    //System.out.println(ch);
                if(ch==sqr){
                    //System.out.println("fstfst"+j);
                    if(j<10){count++;}
                    else{
                    valid=true;
                    play=Long.toString(j);
                        //for (long k = 0; k < play.length()/2; k++) {
                            //String string = args[k];
                            //System.out.println(play.length());
                            //double a = Math.ceil((double)play.length()/2);
                            int res = (play.length()+2-1)/2;
                            
                            for (int k = 0; k < res; k++) {
                            //String string = args[k];
                                //System.out.println("fst"+play);
                                //System.out.println(play.substring(k, k+1));
                                //System.out.println(play.substring(play.length()-1-k, play.length()-k));
                                
                                if(!play.substring(k, k+1).equals(play.substring(play.length()-k-1, play.length()-k))){
                                    //System.out.println(play);
                                    valid=false;
                                    break;
                                }
                                
                            
                            }
                            //double a = play.length()/2;
                            //long b=Math.round(a);
                            //System.out.println(res);
                            
                        //}
                            
                            if(valid==true){
                                
                                //one more check
                                //System.out.println(play);count++;
                                play = Long.toString(ch);
                                res = (play.length()+2-1)/2;
                                for (int k = 0; k < res; k++) {
                            //String string = args[k];
                                //System.out.println("fst"+play);
                                //System.out.println(play.substring(k, k+1));
                                //System.out.println(play.substring(play.length()-1-k, play.length()-k));
                                
                                    if(!play.substring(k, k+1).equals(play.substring(play.length()-k-1, play.length()-k))){
                                        //System.out.println(play);
                                        valid=false;
                                        break;
                                    }
                                
                            
                                }
                                
                               if(valid==true){
                                   //System.out.println(play);
                                   count++;} 
                            }
                    
                    }
                    
                }
                }
             message="Case #"+i+": "+count;
             out.println(message);   
            System.out.println("Case #"+i+": "+count);
        }
    }
}
