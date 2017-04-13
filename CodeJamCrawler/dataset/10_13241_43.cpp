/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class GoogleB {
    public static void main(String args[]) throws Exception{
        Scanner info=new Scanner(new FileReader("C-small-attempt0.in"));
        PrintWriter archivoSalida=new PrintWriter(new FileWriter("salida.txt"), true);
        String linea;
        String ar[];
        String gr[];
        int money=0;
        linea=info.nextLine();
        int casos=Integer.parseInt(linea);
        for (int i = 0; i < casos; i++) {
            money=0;
            linea=info.nextLine();
            ar=linea.split(" ");
            linea=info.nextLine();
            gr=linea.split(" ");
            int vueltas=Integer.parseInt(ar[0]);
            int k=Integer.parseInt(ar[1]);
            LinkedList queue=new LinkedList();
            LinkedList salida=new LinkedList();
            for (int j = 0; j < gr.length; j++) {
                queue.addLast(gr[j]);
            }
            for (int j = 0; j < vueltas; j++) {
                int aux=k;
                int aux1=0;
                for (int l = 0; l < k; l++) {
                    if(queue.isEmpty()){
                        break;
                    }
                    aux1=Integer.parseInt(queue.removeFirst().toString());
                    if(aux1<=aux){
                        salida.addLast(aux1);
                        aux=aux-aux1;
                        money+=aux1;
                    }
                    else{
                        queue.addFirst(aux1);
                    }
                }
                while(!salida.isEmpty()){
                    queue.addLast(salida.removeFirst());
                }
            }
            archivoSalida.println("Case #"+ (i+1)+": "+money);
        }
    }
}
