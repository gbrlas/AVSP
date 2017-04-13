import java.util.*;
import java.io.*;
public class p1 {
    public static int valor(int n){
        return (int)Math.pow(2, n)-1;
    }
    public static void main(String[] args) {
        Scanner leer=null;
        PrintWriter sal=null;
        try{
            leer = new Scanner(new File("A-small-attempt1.in"));
            sal= new PrintWriter("snapper.out");
        }catch(IOException e){        }

        int nCasos=leer.nextInt();
        for(int i=0;i<nCasos;i++){
            int n=leer.nextInt();
            int tamSecuencia=valor(n);
            long k=leer.nextInt();
            if(k>tamSecuencia)
               k=k%(int)Math.pow(2, n);
            sal.print("Case #"+(i+1)+": ");
            if(k<tamSecuencia)
                sal.println("OFF");
            else if(k==tamSecuencia)
                sal.println("ON");
        }
        sal.close();
    }
}