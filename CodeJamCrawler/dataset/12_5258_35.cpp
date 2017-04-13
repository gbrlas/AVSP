
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class code11 {
    
    static String answer(String a){ char [] [] result = {{'a','y'},{'b','h'},{'c','e'},{'d','s'},{'e','o'},{'f','c'},{'g','v'},{'h','x'},{'i','d'},{'j','u'},{'k','i'},{'l','g'},{'m','l'},{'n','b'},{'o','k'},{'p','r'},{'q','z'},{'r','t'},{'s','n'},{'t','w'},{'u','j'},{'v','p'},{'w','f'},{'x','m'},{'y','a'},{'z','q'},{' ',' '}};
                char[] q = a.toCharArray();
    char [] u = new char[q.length];
      for(int y=0;y<u.length;y++){
           int p =(int) q[y];
      if(p== 32){u[y]=result[26][1];}
      else{ u[y]= result[p-97][1];}}
    String str = new String(u); return str;}
    
    
    public static void main(String[] args) throws IOException{
    Scanner c = new Scanner(System.in);
   // System.out.print("give the inputs");
   int times= c.nextInt();
   String y=c.nextLine();
   for(int p=0;p<times;p++){
    String input = c.nextLine();
    String output = answer(input);
    System.out.println("Case #"+(p+1)+":  "+output);
     }
    }
}
