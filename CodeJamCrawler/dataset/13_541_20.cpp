
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author user
 */
public class NewMain {

    /**
     * @param args the command line arguments
     */
    static boolean result= false;
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        
        /*File file = new File("test.txt");  
        FileOutputStream fis = new FileOutputStream(file);  
        PrintStream out = new PrintStream(fis);  
        System.setOut(out);
        */
        
        PrintWriter out = new PrintWriter(new FileWriter("final.txt"), true);
        String message="";
        Scanner br = new Scanner(System.in);
        String cases = br.nextLine();
        int num = Integer.parseInt(cases);
        for (int i = 1; i <= num; i++) {
            //String string = args[i];
            String [][] dim = new String[4][4];
            for (int j = 0; j <4; j++) {
                //String string1 = args[j];
                String input = br.nextLine();
                for (int k = 0; k < 4; k++) {
                    //String[] strings = dim[k];
                    dim[j][k]=input.substring(k, k+1);
                    
                }
                
            }
            
            String fst = "X";
            result = check(fst,dim);
            
            if(result==false){
                String sec = "O";
                result = check(sec,dim);
                
                if(result==false){
                    //check if the game is completed or it's draw
                    
                    boolean dec=false;
                    for (int j = 0; j < dim.length; j++) {
                        if(dec==true){break;}
                        for (int k = 0; k < dim.length; k++) {
                            if(dim[j][k].equals(".")){dec=true;}
                            break;
                        }
                        
                    }
                    
                    if(dec==true){
                        message="Case #"+i+": Game has not completed";
                        out.println(message);
                        System.out.println("Case #"+i+": Game has not completed");
                    }
                    else{
                        message="Case #"+i+": Draw";
                       out.println(message);
                        System.out.println("Case #:"+i+": Draw");}
                }
                else{
                    message="Case #"+i+": O won";
                    out.println(message);
                 System.out.println("Case #"+i+":"+" O won");
                }
                
            }
            else{
                message="Case #"+i+": X won";
                out.println(message);
                System.out.println("Case #"+i+":"+" X won");
            }
            
            
            
            //System.out.println(Arrays.deepToString(dim));
             if(i!=num){String input = br.nextLine();}
             
            //out.close();
            }
            out.close();
        }
    public static boolean check(String fst,String[][] dim){
     boolean ans= false;
        for (int i = 0; i < 4; i++) {
            if(ans==true){break;}
            int count=0;
            for (int j = 0; j < 4; j++) {
                
                  //System.out.println(dim[i][j]);
                    if(!dim[i][j].equals(fst)&& !dim[i][j].equals("T")){
                        //if(){
                        //System.out.println("fst"+fst);
                      //  System.out.println(dim[i][j]);
                        break; 
                        }
                        
                    //}
                else{count++;}
                //System.out.println(count);
                if (count==4){ans = true;}
            }
        }
        
        for (int i = 0; i < 4; i++) {
            //System.out.println(ans);
            if(ans!=true){
                int count=0;
                for (int j = 0; j < 4; j++) {
                  
                    //System.out.println("fst"+fst);
                        //System.out.println(dim[j][i]);
                    //System.out.println(dim[j][i]);
                    if(!dim[j][i].equals(fst)&& !dim[j][i].equals("T")){
                        //if(){
                        //System.out.println("fst"+fst);
                      //  System.out.println(dim[i][j]);
                        break; 
                        }
                    
                    else{count++;}

                    if (count==4){ans = true;
                        //System.out.println("got it");
                    }
                }
            }
        }
        int count=0;
        for (int i = 0; i < 4; i++) {
            if(ans==true){break;}
           
                if(!dim[i][i].equals(fst)&& !dim[i][i].equals("T")){
                        //if(){
                        //System.out.println("fst"+fst);
                      //  System.out.println(dim[i][j]);
                        break; 
                        }
                else{count++;}
               
                if (count==4){ans = true;}
            
        }
        count =0;
        for (int i = 3; i >= 0; i--) {
            if(ans==true){break;}
           
                if(!dim[3-i][i].equals(fst)&& !dim[3-i][i].equals("T")){
                        //if(){
                        //System.out.println("fst"+fst);
                      //  System.out.println(dim[i][j]);
                        break; 
                        }
                else{count++;}
               
                if (count==4){ans = true;}
            
        }
        
        
        
        if(ans==true){return true;}
        else{return false;}
    }
    }

